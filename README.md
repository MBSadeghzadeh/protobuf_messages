# protobuf_messages
protobuf message serialization and deserialization over TCP communication

# How to build

```
sudo apt-get install protobuf-compiler

cmake -B ./build -S . -DCMAKE_INSTALL_PREFIX=./install -DCMAKE_BUILD_TYPE=Debug -DBUILD_WITH_TESTS=ON -DCMAKE_PREFIX_PATH=./install

cmake --build ./build

cmake --install ./build
```
  
