import sys
import os
import time
import shutil
import glob
import subprocess


if len(sys.argv) != 2:
    print(f'Usage: {sys.argv[0]} <firmware.uf2>')
    sys.exit(1)

uf2 = sys.argv[1]

if not os.path.isfile(uf2):
    print(f'File not found: {uf2}')
    sys.exit(1)

dst = f'/run/media/{os.environ['USER']}/RP2350/'
pattern = '/dev/serial/by-id/usb-Raspberry_Pi_Pico_*'

device = glob.glob(pattern)
if device:
    print(f'Found device: "{device[0]}", resetting')
    subprocess.run(['stty', '-F', device[0], '1200'])

if not os.path.isdir(dst):
    print(f'Waiting for "{dst}"')
    for i in range(0, 15):
        print('.', end='')
        sys.stdout.flush()

        if os.path.isdir(dst):
            print()
            break

        time.sleep(1)

    if not os.path.isdir(dst):
        print('Timed out waiting for "{dst}"')
        sys.exit(1)

print(f'Copying "{uf2}" -> "{dst}"')
shutil.copy(uf2, dst)

