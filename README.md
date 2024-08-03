# CustomEmitConnect

Welcome to the CustomEmitConnect project! This project demonstrates a custom implementation of signal-slot mechanisms in C++. It is designed to work seamlessly with both custom slots and Qt slots, providing flexibility in event-driven programming.

## Features

- Custom `Signal` class to create and emit signals.
- Compatibility with both custom slots and Qt slots.
- Simple API to connect signals to slots.
- Example usage demonstrating the functionality.

## Getting Started

### Prerequisites

Ensure you have the following tools installed:

- C++ compiler (e.g., g++, clang++)
- Qt development framework (for Qt slots)

### Cloning the Repository

```bash
git clone https://github.com/itzmew/CustomEmitConnect.git
cd CustomEmitConnect
```

### Building the Project

1. **Custom Slots Only:**

   ```bash
   g++ -o custom_slots_example custom_slots_example.cpp
   ./custom_slots_example
   ```

2. **Qt Slots:**

   Ensure you have Qt installed and properly configured.

   ```bash
   qmake
   make
   ./qt_slots_example
   ```

## Usage

### Defining a Signal

To define a signal, create an instance of the `Signal` class:

```cpp
Signal<int> signal;
```

### Connecting Slots

You can connect both custom slots and Qt slots to signals:

#### Custom Slots

```cpp
void customSlot(int value) {
    std::cout << "Custom Slot received: " << value << std::endl;
}

signal.connect(&customSlot);
```

#### Qt Slots

```cpp
class MyObject : public QObject {
    Q_OBJECT

public slots:
    void qtSlot(int value) {
        qDebug() << "Qt Slot received:" << value;
    }
};

MyObject obj;
signal.connect(&obj, &MyObject::qtSlot);
```

### Emitting Signals

To emit a signal and invoke connected slots:

```cpp
signal.emit(42);
```

## Contributing

Contributions are welcome! Please feel free to submit a pull request or open an issue if you encounter any problems or have suggestions for improvements.

## Contact

For any questions or inquiries, please contact [me](https://github.com/itzmew).
