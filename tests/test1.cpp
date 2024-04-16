#include <SampleMessage.pb.h>
#include <iostream>

int main()
{
    // Create a TemperatureData object
    TemperatureData temperature_data;
    temperature_data.set_temperature(25.5); 
    temperature_data.set_unit("Celsius");   
    temperature_data.set_timestamp(1631990165000); 
    temperature_data.set_device_id("123456");
    temperature_data.set_version("1.0.0");

    // Serialize TemperatureData object to a binary string
    std::string serialized_data;
    temperature_data.SerializeToString(&serialized_data);

    // Display serialized data (for demonstration purposes)
    std::cout << "Serialized data: " << serialized_data << std::endl;

    // Deserialize binary string back to TemperatureData object
    TemperatureData deserialized_data;
    deserialized_data.ParseFromString(serialized_data);

    // Display deserialized data
    std::cout << "Temperature: " << deserialized_data.temperature() << std::endl;
    std::cout << "Unit: " << deserialized_data.unit() << std::endl;
    std::cout << "Timestamp: " << deserialized_data.timestamp() << std::endl;
    std::cout << "Device ID: " << deserialized_data.device_id() << std::endl;
}