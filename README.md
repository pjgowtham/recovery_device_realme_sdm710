# android_device_realme_RMX1921
For building Orangefox for Realme XT

Orangefox device tree for Realme XT

## Features

Works:

- Everything

## Compile

First checkout manifest :

```
repo init --depth=1 -u https://gitlab.com/OrangeFox/Manifest.git -b fox_9.0
repo sync
```

Then add these projects to .repo/manifest.xml:

```xml
<project path="device/realme/RMX1921" name="device/RMX1921" remote="gitlab" revision="master" />
```

Finally execute these:

```
. build/envsetup.sh
lunch omni_RMX1921-eng
mka recoveryimage ALLOW_MISSING_DEPENDENCIES=true
```

To test it:

```
fastboot flash /path/to/recovery.img
and then
Flash the zip through the recovery for addon support.
```


## Thanks

- Thanks to @mauronfrio for the TWRP tree for realme XT
