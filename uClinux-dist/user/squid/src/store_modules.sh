#!/bin/sh
echo "/* automatically generated by $0 $*"
echo " * do not edit"
echo " */"
echo "#include \"squid.h\""
echo ""
for module in "$@"; do
   echo "extern STSETUP storeFsSetup_${module};"
done
echo "void storeFsSetup(void)"
echo "{"
for module in "$@"; do
   echo "	storeFsAdd(\"$module\", storeFsSetup_${module});"
done
echo "}"
