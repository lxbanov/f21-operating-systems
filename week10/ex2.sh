mkdir week01
mkdir week10
echo "Aleksandr Lobanov" > ./week01/file.txt
link ./week01/file.txt ./week10/_ex2.txt
find . -inum $(ls -i ./week01/file.txt | awk '{print $1}') > ex2.txt
find . -inum $(ls -i ./week01/file.txt | awk '{print $1}') -exec rm {} \;

