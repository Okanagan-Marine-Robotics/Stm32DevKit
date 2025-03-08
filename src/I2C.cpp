#include <Wire.h>

class I2CHandler {
  public:
    I2CHandler(uint8_t address);
    void Init();
    void SendData(uint8_t* data, uint8_t size);
    bool ReceiveData(uint8_t* data, uint8_t size);

  private:
    uint8_t deviceAddress;
};

I2CHandler::I2CHandler(uint8_t address) : deviceAddress(address) {}

void I2CHandler::Init() {
  Wire.begin(deviceAddress);  // Start the I2C bus as slave with the given address
}

void I2CHandler::SendData(uint8_t* data, uint8_t size) {
  Wire.beginTransmission(deviceAddress);  // Start transmission to device
  for (uint8_t i = 0; i < size; i++) {
    Wire.write(data[i]);  // Write data byte by byte
  }
  Wire.endTransmission();  // End the transmission
}

bool I2CHandler::ReceiveData(uint8_t* data, uint8_t size) {
  Wire.requestFrom(deviceAddress, size);  // Request data from slave device
  uint8_t index = 0;

  while (Wire.available() && index < size) {
    data[index] = Wire.read();  // Read the incoming byte
    index++;
  }

  return index == size;  // Return true if the expected amount of data was received
}
