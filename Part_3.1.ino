#if CONFIG_FREERTOS_UNICORE
static const BaseType_t app_cpu = 0;
#else
static const BaseType_t app_cpu = 1;
#endif

static const int led_pin=2;

void toggleLED_1(void *parameter) {
  while(1) {
    digitalWrite(led_pin, HIGH);
    vTaskDelay(500 / portTICK_PERIOD_MS);
    digitalWrite(led_pin, LOW);
    vTaskDelay(500 / portTICK_PERIOD_MS);
  }
}
void toggleLED_2(void *parameter) {
  while(1) {
    digitalWrite(led_pin, HIGH);
    vTaskDelay(300 / portTICK_PERIOD_MS);
    digitalWrite(led_pin, LOW);
    vTaskDelay(300 / portTICK_PERIOD_MS);
  }
}

void setup() {

  pinMode(led_pin, OUTPUT);
  xTaskCreatePinnedToCore(toggleLED_1,"Toggle 1",1024,NULL,1,NULL,app_cpu);    
  xTaskCreatePinnedToCore(toggleLED_2,"Toggle 1",1024,NULL,1,NULL,app_cpu); 

}

void loop() {
 
}