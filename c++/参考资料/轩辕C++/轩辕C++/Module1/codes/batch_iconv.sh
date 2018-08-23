find . \( -name "*.java" -o  -name "*.jsp" \) -exec iconv -f gbk -t utf8 {} -o {}.bak \;
find . \( -name "*.java" -o  -name "*.jsp" \) -exec rm {} \;
find . -name "*.bak" -exec rename 's/\.bak$//' {} \;
