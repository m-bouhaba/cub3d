#!/usr/bin/env python3
import sys
from pathlib import Path

def hex_to_rgb(h):
    h = h.lstrip('#')
    return tuple(int(h[i:i+2],16) for i in (0,2,4))

def rgb_to_hex(rgb):
    return '#{:02X}{:02X}{:02X}'.format(*rgb)

def blend(orig, tint, alpha=0.6):
    # return round(orig*(1-alpha) + tint*alpha)
    return tuple(min(255, max(0, int(round(orig[i]*(1-alpha) + tint[i]*alpha)))) for i in range(3))

if __name__ == '__main__':
    if len(sys.argv) < 4:
        print('Usage: recolor_xpm.py <input.xpm> <output.xpm> <tint_hex>')
        sys.exit(2)
    inp = Path(sys.argv[1])
    out = Path(sys.argv[2])
    tint_hex = sys.argv[3]
    if not inp.exists():
        print('Input not found:', inp)
        sys.exit(1)
    tint_rgb = hex_to_rgb(tint_hex)
    data = inp.read_text().splitlines()
    # find first quoted header line
    header_idx = None
    for i,l in enumerate(data):
        # find quoted part on the line
        if '"' in l:
            first = l.find('"')
            second = l.find('"', first+1)
            if second != -1:
                quoted = l[first+1:second]
                parts = quoted.split()
                if len(parts) >= 4 and parts[0].isdigit():
                    header_idx = i
                    break
    if header_idx is None:
        print('Could not find header line in XPM:', inp)
        sys.exit(1)
    # extract quoted header content
    line = data[header_idx]
    first = line.find('"')
    second = line.find('"', first+1)
    header = line[first+1:second]
    w,h,ncolors,ch = header.split()
    ncolors = int(ncolors)
    # color table starts next line
    col_start = header_idx+1
    col_end = col_start + ncolors
    if col_end > len(data):
        print('XPM seems truncated (ncolors out of range)')
        sys.exit(1)
    out_lines = list(data)
    for i in range(col_start, col_end):
        line = data[i]
        # operate only inside quoted portion (between first and second quote)
        if '"' in line:
            first = line.find('"')
            second = line.find('"', first+1)
            if second == -1:
                continue
            quoted = line[first+1:second]
            # find a hex color in the quoted segment
            hash_pos = quoted.find('#')
            if hash_pos != -1 and len(quoted) >= hash_pos+7:
                orig_hex = quoted[hash_pos:hash_pos+7]
                try:
                    orig_rgb = hex_to_rgb(orig_hex)
                    new_rgb = blend(orig_rgb, tint_rgb, alpha=0.6)
                    new_hex = rgb_to_hex(new_rgb)
                    # replace only the hex in the quoted part
                    new_quoted = quoted[:hash_pos] + new_hex + quoted[hash_pos+7:]
                    # rebuild the full line preserving leading/trailing characters
                    new_line = line[:first+1] + new_quoted + line[second:]
                    out_lines[i] = new_line
                except Exception:
                    pass
    out.write_text('\n'.join(out_lines))
    print('Wrote', out)
