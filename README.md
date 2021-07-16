# android_device_realme_(realme_sdm710)
Recovery tree for realme sdm710 devices

## Features

Works:

 - Everything

## Compile

First checkout manifest :

```
repo init --depth=1 -u git://github.com/minimal-manifest-twrp/platform_manifest_twrp_aosp.git -b twrp-11
repo sync
```

Then clone the current device tree onto device/realme/realme_sdm710


Finally execute these:

```
. build/envsetup.sh
lunch omni_RMX1921-eng
mka recoveryimage ALLOW_MISSING_DEPENDENCIES=true
```

To test it:

```
fastboot flash /path/to/recovery.img
```


## Credits

- Thanks to @mauronfrio for the TWRP tree for realme X/XT
- TWRP team
