This hypervisor has only been tested on FreeBSD 10.x as of this writing and
requires a true Intel processor (not AMD).

To get started, you need a FreeBSD virtual machine. I'm primarily testing
under Hyper-V using a Generation 2 VM. To get FreeBSD, you need an old
version like 10.4. You can get an ISO image from here:
  http://ftp-archive.freebsd.org/pub/FreeBSD-Archive/old-releases/ISO-IMAGES/10.4/FreeBSD-10.4-RELEASE-amd64-uefi-disc1.iso

After installing the VM, you need to mark it such that it uses Nested
Virtualization. Using PowerShell on your VM host, try this (substitute
your virtual machine name for <VMName>):
  Set-VMProcessor -VMName <VMName> -ExposeVirtualizationExtensions $true

Then restart the VM (you shouldn't notice any change).

We need a working `git`... see the section below.

Then clone the repository:
  git@github.com:wrigjl/cgcvmx.git

You need to patch the FreeBSD source code slightly. In /sys/amd64, there's a function
definition for pmap_pte. It needs to look like this:
  pt_entry *pmap_pte(pmap_t pmap, vm_offset_t va);

(I.e. remove the inline definition parts... Our hypervisor needs this function to
be callable and it won't be if it is "inline").

Now rebuild and install the kernel:
  cd /sys/amd64/conf
  config GENERIC
  cd ../compile/GENERIC
  make && make install && reboot

With the new kernel installed, go to where you cloned the hypervisor:
  cd cgcvmx
  make
  su
  kldload ./cgcvmx64.ko

If things went well, you'll get a message about being in the matrix (without crashing).

## Getting `git`

Building git on this old version of FreeBSD isn't straightfoward. Here's what I did:

```
ftp http://ftp.gnu.org/gnu/make/make-4.4.tar.gz
tar xzf make-4.4.tar.gz
cd make-4.4
./configure
make
su
        # as root
        make install
        exit
cd ..
ftp http://mirrors.edge.kernel.org/pub/software/scm/git/git-2.44.0.tar.gz
tar xzf git-2.44.0.tar.gz
cd git-2.44.0
./configure --without-tcltk
/usr/local/bin/make
su
        # as root
        make install
        exit
```

