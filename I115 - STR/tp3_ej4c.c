// DOC: https://docs.aws.amazon.com/es_es/freertos/latest/userguide/dev-guide-freertos-kernel.html
#include <Arduino_FreeRTOS.h>
#include <semphr.h>

SemaphoreHandle_t mutex;
SemaphoreHandle_t sem;

void TaskSTR1(void *pvParameters){
  while(true){
    if (xSemaphoreTake(mutex, (TickType_t) 15) == pdTRUE){
      Serial.println("task 1 | ");
      xSemaphoreGive(mutex);
    }
      
    vTaskDelay( 100 / portTICK_PERIOD_MS );
  }
}

void TaskSTR2(void *pvParameters){
  // int i=0;

  while(true){
    if (xSemaphoreTake(mutex, (TickType_t) 15) == pdTRUE){
      Serial.println("task 2 | ");
      xSemaphoreGive(mutex);
    }
    
    vTaskDelay( 100 / portTICK_PERIOD_MS );
  }
}

void TaskSTR3(void *pvParameters){
  while(true){
    
    if (xSemaphoreTake(mutex, (TickType_t) 15) == pdTRUE){
      while (xSemaphoreTake(sem, (TickType_t) 15) == pdTRUE){
        Serial.println("task 3 | ");
      }

      for(int i=0; i<3; i++) xSemaphoreGive(sem);
      xSemaphoreGive(mutex);
    }
    
    vTaskDelay( 100 / portTICK_PERIOD_MS );
  }
}

void TaskMillis(void *pvParameters){
  while(true){
    Serial.println();
    Serial.println(millis());
    vTaskDelay(1000 / portTICK_PERIOD_MS);
  }
}

// -----------------------------------

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  mutex = xSemaphoreCreateMutex();
  sem = xSemaphoreCreateCounting(3,3);
  xSemaphoreGive(mutex);

  // creacion de tareas
 
  xTaskCreate(TaskSTR3, "Tarea 3", 128, NULL, 1, NULL);
  xTaskCreate(TaskSTR1, "Tarea 1", 128, NULL, 1, NULL);
  xTaskCreate(TaskSTR2, "Tarea 2", 128, NULL, 1, NULL);
  // xTaskCreate(TaskMillis, "millis", 128, NULL, 2, NULL);
}

void loop() {
 
}