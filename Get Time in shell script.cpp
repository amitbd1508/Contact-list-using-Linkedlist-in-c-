

#!/bin/bash
NOW=$(date +"%r")

echo "===============Time is $NOW===================="

hour=${NOW:0:2}
min=${NOW:3:2}
sec=${NOW:6:2}
t=${NOW:9:2}

wh="$(whoami)"



if [[ ( "$t" = "AM" && "$hour" = "12" ) || ( "$t" = "AM" && "$hour" -ge 1 && "$hour" -le 11 ) ]]
then echo "Good Morning  $wh"
elif [[ ( "$t" = "PM" && "$hour" = "12" ) || ( "$t" = "PM" && "$hour" -ge 1 && "$hour" -le 5 ) ]]
then echo "Good Afternoon  $wh"
elif [[ ( "$t" = "PM" && "$hour" -ge 6 && "$hour" -le 11 ) ]]
then echo "Good Evening  $wh"
fi
