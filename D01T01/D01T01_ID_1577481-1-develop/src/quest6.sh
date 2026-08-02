#!/bin/bash
cd ai_help/
chmod +x *.sh
bash keygen.sh
cd key
rm file*
cd ..
bash unifier.sh
mv main.key key