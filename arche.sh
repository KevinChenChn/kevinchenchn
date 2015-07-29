tar -zxvf bitvisor-1.4.tar.gz
cd bitvisor-1.4
sudo make
sudo sed -i  "1,/export linux_gfx_mode/ {/export linux_gfx_mode/a\\
menuentry 'Bitvisor'  {\\
	insmod ext2\\
	multiboot /boot/bitvisor.elf\\
	set root='hd0,msdos1'\\
	module	 	/boot/module1.bin\\
	module 	/boot/module2.bin\\
            }
}" /boot/grub/grub.cfg
cd boot/login-simple/
sudo cp bitvisor.conf.tmpl bitvisor.conf
echo  "Do you want to use USB encrypt?(y/n) \c"
 while :  # loop  
    do  
    if read var
        then  
            case $var in  
                Y|y) #Y  
                    echo  "\n Update  Recovery\n"
		sudo sed -i "s/vmm.driver.usb.uhci=.*/ vmm.driver.usb.uhci=1/g" /home/nfs/bitvisor-1.4/boot/login-simple/bitvisor.conf
		sudo sed -i "s/vmm.driver.usb.ehci=.*/ vmm.driver.usb.ehci=1/g" /home/nfs/bitvisor-1.4/boot/login-simple/bitvisor.conf
                      break  
                    ;;  
                N|n) #N  
                    echo "\n Not Update Recovery\n" 
                    	sudo sed -i "s/vmm.driver.usb.uhci=.*/ vmm.driver.usb.uhci=0/g" /home/nfs/bitvisor-1.4/boot/login-simple/bitvisor.conf
		sudo sed -i "s/vmm.driver.usb.ehci=.*/ vmm.driver.usb.ehci=0/g" /home/nfs/bitvisor-1.4/boot/login-simple/bitvisor.conf
                      break  
                    ;;  
                *) #input error repeat  
                    echo -e "\n input parameter error !! \n"  
                    continue  
            esac   
    fi   
    done  
    echo  "Do you want to use ATA encrypt?(y/n) \c"
 while :  # loop  
    do  
    if read var
        then  
            case $var in  
                Y|y) #Y  
                    echo  "\n Update  Recovery\n"
                    sudo sed -i "s/vmm.driver.ata=.*/ vmm.driver.ata=1/g" /home/nfs/bitvisor-1.4/boot/login-simple/bitvisor.conf
                    sudo sed -i "s/storage.conf0.host_id=.*/storage.conf0.host_id=-1/g" /home/nfs/bitvisor-1.4/boot/login-simple/bitvisor.conf
                    sudo sed -i "s/storage.conf0.device_id=.*/storage.conf0.device_id=-1/g" /home/nfs/bitvisor-1.4/boot/login-simple/bitvisor.conf
                    sudo sed -i "s/#storage.conf0.type=ATA/storage.conf0.type=AHCI/g" /home/nfs/bitvisor-1.4/boot/login-simple/bitvisor.conf
                    echo "witch sda do you want to encrypt?(number)"
                     while :  # loop  
                        do  
                             if read sda
                            then  
                             case $sda in  
                             1)  
                            echo  "\n Update  Recovery\n"
                             sda_low=$(sudo fdisk -l | awk '{if($1~/\/dev/)print $3}' | awk '{if(NR==1)print $1}')
                             sda_high=$(sudo fdisk -l | awk '{if($1~/\/dev/)print $4}' | awk '{if(NR==1)print $1}')
                             sudo sed -i "s/storage.conf0.lba_low=.*/ storage.conf0.lba_low=$sda_low/g" /home/nfs/bitvisor-1.4/boot/login-simple/bitvisor.conf
                             sudo sed -i "s/storage.conf0.lba_high=.*/ storage.conf0.lba_low=$sda_high/g" /home/nfs/bitvisor-1.4/boot/login-simple/bitvisor.conf
                            break  
                             ;;  
                             2|3|4|5|6|7|8|9|10) 
                             echo "\n Update Recovery\n" 
                             sda_low=$(sudo fdisk -l | awk '{if($1~/\/dev/)print $2,$3,$4}' | awk -v sda=$sda '{if(NR==sda)print $1}')
                             sda_high=$(sudo fdisk -l | awk '{if($1~/\/dev/)print $2,$3,$4}' | awk -v sda=$sda '{if(NR==sda)print $2}')
                             sudo sed -i "s/storage.conf0.lba_low=.*/ storage.conf0.lba_low=$sda_low/g" /home/nfs/bitvisor-1.4/boot/login-simple/bitvisor.conf
                             sudo sed -i "s/storage.conf0.lba_high=.*/ storage.conf0.lba_low=$sda_high/g" /home/nfs/bitvisor-1.4/boot/login-simple/bitvisor.conf
                             break  
                             ;;  
                           *) #input error repeat  
                             echo -e "\n input parameter error !! \n"  
                             continue  
                            esac   
                            fi   
                            done  
                      break  
                    ;;  
                N|n) #N  
                    echo "\n Not Update Recovery\n" 
                    sudo sed -i "s/vmm.driver.ata=.*/ vmm.driver.ata=0/g" /home/nfs/bitvisor-1.4/boot/login-simple/bitvisor.conf
                      break  
                    ;;  
                *) #input error repeat  
                    echo -e "\n input parameter error !! \n"  
                    continue  
            esac   
    fi   
    done  
sudo make
sudo cp module1.bin /boot/  
sudo cp module2.bin /boot/

cd /home/nfs/bitvisor-1.4/
sudo make
sudo cp bitvisor.elf /boot/


