fl="data.txt"
ch=0
while [ 1 ]
do
echo -e "\n1.Display\n2.Insert\n3.Delete\n4.Update\n5.Exit"
read ch
	case $ch in
	
	1)
	cat data.txt;;

	2)
	echo "Enter roll no"
	read roll
	echo "Enter name: "
	read name
	echo "Enter dept: "
	read dept
	echo "Enter sgpa: "
	read sgpa
	echo "$roll|$name|$dept|$sgpa" >> $fl
	echo -e "Successfully Inserted\n";;

	3)
	echo "Enter roll number to delete: "
	read roll
	if grep -q $roll $fl; then
	ln=`grep -v $roll $fl`
	echo "$ln">$fl
	echo -e "Successfully Deleted\n"
	else
	echo "Not possible roll not present"
	fi;;

	4)
	echo "Enter roll number to update: "
	read roll
	if grep -q $roll $fl; then
	echo "Enter name: "
	read name
	echo "Enter dept: "
	read dept
	echo "Enter sgpa: "
	read sgpa
	ln=`grep -v $roll $fl`
	echo "$ln" > $fl
	echo "$roll|$name|$dept|$sgpa" >> $fl
	echo -e "Successfully updated\n"
	else
	echo "Roll not present"
	fi;;
	5)
	exit;;
	*)
	echo "Invalid\n";;
	esac
	
done
