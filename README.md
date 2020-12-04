p11-kit for Unikraft
=============================

This is the port of p11-kit for Unikraft as an external library.

### Dependencies
It depends on the following libraries that need to be added to `Makefile`
in this order:

* networking, e.g `lwip`
* multi-threading, e.g `pthread-embedded`
* libc, e.g `newlib`

For example:
 `...$(UK_L)/p11-kit:$(UK_L)/lwip:$(UK_L)/pthread-embedded:$(UK_L)/newlib...`

##### Additional configurations
For the library to work, `ppoll` must be disabled in `lwip`.

### The file system
Because the 9PFS filesystem is used, you will have to go under
"Library Configuration" -> "vfscore" -> "Default root device" and set your mount
tag to the one you will use. The tag `rootfs` can be used also.

### How to run
In order to run the library in your application, you will have to add the
following lines to your `qemu` script to make it use a filesystem:
```
-fsdev local,security_model=none,id=myid,path=/your/path/here \
-device virtio-9p-pci,id=fs0,fsdev=myid,mount_tag=rootfs,disable-modern=on,\
 disable-legacy=off
```

When running `make`, the `Makefile` will automatically create the file structure
needed inside a folder named `fs0` inside your app folder. Please make sure
there isn't any other folder named `fs0` before running `make`.

### How to test
To run the tests included in the library you will have to call
`libp11kit_test_main(int argc, char *argv[]);`. Do not forget to check that
you want to build the test suite under `libp11-kit` in the `menuconfig`

The library is compatible with KVM (Linuxu too in the future).

## Missing features
Identified missing features that cause failed tests:
 1. `basename` symbol missing from `newlib`
 2. `fork` and `execv` support missing
 3. dynamic library linking support missing
 4. `getprogname` missing
 5. `setenv` and `getenv` do not work properly
 6. path expansion from `~` not working properly
 7. `mkdtemp` works, but it needs patching

Other underlying problems might appear after the ones above are fixed.

The following tests fail currently due to the above missing functionalities:
 - `test-compat` (1)
 - `test-path` (6)
 - `test-runtime` (7)
 - `test-url` (5)
 - `test-conf` (unknown, failed on host too)
 - `test-deprecated` (3)
 - `test-init` (3 + 2)
 - `test-iter` (3)
 - `test-managed` (partially)
 - `test-modules` (1)
 - `test-pin` (partially)
 - `test-progname` (4)
 - `test-proxy` (7)
 - `test-rpc` (unknown)
 - `test-server` (4)
 - `test-transport` (4)

Please refer to the `README.md` as well as the documentation in the `doc/`
subdirectory of the main unikraft repository.
