#define CONFIG_ARCH_CPU_TYPE "armv7-m"
#define CONFIG_ETHERNETMAC 1
#define CONFIG_LITEOS_ENABLE 1
#define CONFIG_AT_ENABLE 1
#define CONFIG_AT_DEVNAME "atdev"
#define CONFIG_AT_OOBTABLEN 6
#define CONFIG_AT_RECVMAXLEN 1024
#define CONFIG_AT_TASKPRIOR 10
#define CONFIG_CJSON_ENABLE 1
#define CONFIG_DRIVER_ENABLE 1
#define CONFIG_LINKLOG_ENABLE 1
#define CONFIG_LINKQUEUE_ENABLE 1
#define CONFIG_LINKDEMO_ENABLE 1
#define CONFIG_STIMER_ENABLE 1
#define CONFIG_STIMER_STACKSIZE 2048
#define CONFIG_STIMER_TASKPRIOR 10
#define CONFIG_TCIP_AL_ENABLE 1
#define CONFIG_LWIP_ENABLE 1
#define CONFIG_DTLS_AL_ENABLE 1
#define CONFIG_MBEDTLS_ENABLE 1
#define CONFIG_MBEDTLS_CERT 1
#define CONFIG_MQTT_AL_ENABLE 1
#define CONFIG_PAHO_MQTT 1
#define CONFIG_OCSERVICES_ENABLE 1
#define CONFIG_OCMQTT_ENABLE 1
#define CONFIG_OCMQTT_ATCMD 1
#define CONFIG_OC_MQTT_V5 1
#define CONFIG_OC_TINYMQTTV5_ENABLE 1
#define CONFIG_OC_MQTTV5_PROFILE 1
#define CONFIG_OC_MQTTV5_DEMO 1
#define CONFIG_SHELL_ENABLE 1
#define CONFIG_SHELL_TASK_STACKSIZE 2048
#define CONFIG_SHELL_TASK_PRIOR 10
#define CONFIG_IOT_LINK_CONFIGFILE "config.h"
