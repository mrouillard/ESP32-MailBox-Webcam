# ESP32 MaiBox / Webcam

ESP32 Cam project for timelaps and streaming.

The project was started with the code of [bitluni/ESP32CamTimeLapse](https://github.com/bitluni/ESP32CamTimeLapse).

Then the PlatformIO version was forked from [JackGruber/ESP32-Timelaps-Webcam](https://github.com/JackGruber/ESP32-Timelaps-Webcam).

I have added NTP, mDNS and an optional parameter to trigger the LED flash when taking a still.
@WIP I am trying to add SSL certificate to force https only for security purposes.

## Configure

* Rename `include\wifi_credentials.example` to `include\wifi_credentials.h` and enter your WiFi credentials in the file.
* Remove the comment for your board in `include\pins_camera.h` and comment all other boards
* modify settings.h `LOCAL_NAME` to change the local name. Defaut value is `bal` which gives a local name `bal.local`.
* modify settings.h `NTP_SERVER` to change the ntp server. Default is `fr.pool.ntp.org`

## Take a still with flash on

* set the slider to on in the web interface or call `{url}/control?var=flash&val=1` before calling `{url}/capture`

## Create MP4 from timelapse JPG

Converting the images to a video you can use [ffmpeg](https://www.ffmpeg.org/download.html) encoder.

```bash
ffmpeg.exe -r 60 -f image2 -i "C:\Temp\timelapse\pic%05d.jpg"  -codec libx264 -crf 23 -pix_fmt yuv420p -vf "transpose=1" "C:\Temp\timelapse\timelapse.mp4"
```

### Parameters

* `-r <rate>` set the framerate (fps)
* `-f <fmt>` force input format
* `-i <infile>` inputfile, `%05d` means that all files from 00000 to 99999 are used
* `-codec <codec>` Set the video codec
* `-crf <crf>` CRF scale is 0–51, where 0 is lossless, 23 is the default, and 51 is worst quality possible
* `-pix_fmt <pixel format>` specifies the pixel format
* `-start_number <number>` defines the start number, if not to be started at picture 0
* `-vframes <number>` specifies the number frames/images in the video, if not all images should be used
* `-vf "transpose=<number>"` Rotating: 0 = 90° Counterclockwise, 1 = 90° Clockwise, 2 = 90° Counterclockwise, 3 = 90° Clockwise and Vertical Flip. Use `-vf "transpose=2,transpose=2"` for 180 degrees

## @TODO

* secure web interface with SSL (self-generated certificate)
* Add DeepSleep option for timelapse
* Save configuration from web permanently

## Links

* [Original GitHub repro ESP32CamTimeLapse](https://github.com/bitluni/ESP32CamTimeLapse)
* [Project page from the ESP32CamTimeLapse](https://bitluni.net/esp32camtimelapse)
* [FFmpeg download](https://www.ffmpeg.org/download.html)
