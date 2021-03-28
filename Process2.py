import os
import sys
import subprocess

if (len(sys.argv)<3):
  print("No working directory or destination specified")
  print("Use Process2 'work_directory' 'destination'")
  sys.exit(-1)

directory = sys.argv[1]
destination = sys.argv[2]

files = os.listdir(path=directory)
for file in files:
  code = subprocess.call(["./Process1", directory + "/" + file, destination])
  print("exit code = " + str(code))
