sudo add-apt-repository ppa:phablet-team/tools
sudo apt-get update       
sudo apt-get --force-yes --yes install android-tools-adb

echo "starting adb"
gcc lock_check.c
sudo adb logcat -c
adb logcat -s "OSLOCK" | cut -c 44- | sudo ./a.out
        
