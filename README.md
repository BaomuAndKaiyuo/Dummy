# Dummy
This is a dummy driver that does nothing. To deploy and start this dummy driver in the target computer, please attach a kernel debugger as there is no digital signature signed for this driver. Please carefully use this driver in your LAB. I have no responsibilties if this driver causes any harm on your computer.

To use this driver:

Copy dummy.sys to C:\Windows\System32\Drivers
sc create dummy type= kernel start= demand error= normal binPath= System32\Drivers\dummy.sys DisplayName= SwissCheese
sc query dummy
sc start dummy
