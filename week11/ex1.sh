fallocate -l $((2048*1024*1024)) lofs.img
sudo losetup -fP lofs.img
sudo losetup -a 
sudo mkfs.ext4 lofs.img
mkdir lofsdisk
sudo mount -o loop lofs.img lofsdisk
