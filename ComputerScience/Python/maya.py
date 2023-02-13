########################
# -------------------- #
# (C)2023 madoodia.com #
# -------------------- #
########################

import os
from maya import cmds

sels = cmds.ls(sl=True)

for sel in sels:
  rels = cmds.listRelatives(sel, ad=True, type="transform")
  for rel in rels:
    conns = cmds.listConnections(rel, s=True, d=False, type="mesh")
    if conns:
      cmds.select(rel, r=True)
      cmds.delete()

