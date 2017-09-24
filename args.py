import sys

if sys.argv[1][1] == 't':
  print "t is promoted"
  if sys.argv[2] == "script":
    print "Delete Windows ON"
  else:
    print "No doom today"
else:
  print "rekt"

def kw(**kwargs):
  for arg in kwargs:
    print kwargs[arg],arg

kw(a=1, b="12")

