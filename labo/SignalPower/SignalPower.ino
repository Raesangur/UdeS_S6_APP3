
#include "WiFi.h"

void setup()
{
    Serial.begin(115200);

    // Set WiFi to station mode and disconnect from an AP if it was previously connected.
    WiFi.mode(WIFI_STA);
    WiFi.disconnect();
    delay(100);
 }

void loop()
{
    // WiFi.scanNetworks will return the number of networks found.
    int n = WiFi.scanNetworks();
    for (int i = 0; i < n; ++i) {
      char *enc;
      switch (WiFi.encryptionType(i))
            {
            case WIFI_AUTH_OPEN:
                enc = "open";
                break;
            case WIFI_AUTH_WEP:
                enc = "WEP";
                break;
            case WIFI_AUTH_WPA_PSK:
                enc = "WPA";
                break;
            case WIFI_AUTH_WPA2_PSK:
                enc = "WPA2";
                break;
            case WIFI_AUTH_WPA_WPA2_PSK:
                enc = "WPA+WPA2";
                break;
            case WIFI_AUTH_WPA2_ENTERPRISE:
                enc = "WPA2-EAP";
                break;
            case WIFI_AUTH_WPA3_PSK:
                enc = "WPA3";
                break;
            case WIFI_AUTH_WPA2_WPA3_PSK:
                enc = "WPA2+WPA3";
                break;
            case WIFI_AUTH_WAPI_PSK:
                enc = "WAPI";
                break;
            default:
                enc = "unknown";
            }
      Serial.printf("ssid=%s security=%s channel=%d rssi=%d\n", WiFi.SSID(i).c_str(), enc, WiFi.channel(i), WiFi.RSSI(i));

    }
    Serial.printf("Scan complete, found %d APs.\n", n);
    // Delete the scan result to free memory for code below.
    WiFi.scanDelete();
}
