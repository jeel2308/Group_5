# Open door from remote location

In this project,we have developed smart door lock, which allows to lock/unlock door from remote location using your smartphone.

### Prerequisites

1. NodeMCU
2. ServoMotor
3. Adafruit IO Account
4. IFTTT App
5. Install following libraries in Arduino IDE from GitHub
   * ESP8266WiFi
   * Adafruit_MQTT_Library  
6. Android App


### Installing

DownLoad our source code from here [Link]().

Replace following with your Wi-Fi name and password
```
  #define WLAN_SSID  "Wi-Fi name"
  #define WLAN_PASS  "Wi-Fi password"
```

Replace following with your Adafruit IO credential
```
  #define AIO_USERNAME "Adafruit IO id"
  #define AIO_KEY      "Adafruit IO key"
```
Now Upload this Code on NodeMCU using Arduino IDE. If everything will be fine,then you can see "MQTT Connected!" on serial monitor.

Now Setup IFTTT applet using following settings.

<img src="screenshot.png" width="300" />

You can do same for unlocking the door.


### Break down into end to end tests

Explain what these tests test and why

```
Give an example
```

### And coding style tests

Explain what these tests test and why

```
Give an example
```

## Deployment

Add additional notes about how to deploy this on a live system

## Built With

* [Dropwizard](http://www.dropwizard.io/1.0.2/docs/) - The web framework used
* [Maven](https://maven.apache.org/) - Dependency Management
* [ROME](https://rometools.github.io/rome/) - Used to generate RSS Feeds

## Contributing

Please read [CONTRIBUTING.md](https://gist.github.com/PurpleBooth/b24679402957c63ec426) for details on our code of conduct, and the process for submitting pull requests to us.

## Versioning

We use [SemVer](http://semver.org/) for versioning. For the versions available, see the [tags on this repository](https://github.com/your/project/tags). 

## Authors

* **Billie Thompson** - *Initial work* - [PurpleBooth](https://github.com/PurpleBooth)

See also the list of [contributors](https://github.com/your/project/contributors) who participated in this project.

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details

## Acknowledgments

* Hat tip to anyone whose code was used
* Inspiration
* etc
