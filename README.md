# **Port Driver based on AUTOSAR Layered Architecture v4.0.3 for Tiva-C (TM4C123GH6PM)**
This is a header file Port.h for the TM4C123GH6PM microcontroller - Port Driver. This Port Driver is based on the AUTOSAR layered architecture v4.0.3 and provides APIs for initializing the Port Driver, setting the direction of a pin, refreshing the port direction, setting pin mode, and getting the version information.

# **Installation**
This header file Port.h should be included in your project's source code directory.

# **Usage**
1. Include Port.h header file in your source code.
2. Initialize the Port Driver using Port_Init() function with a pointer to a configuration structure of type Port_ConfigType.
3. Set the direction of a pin using Port_SetPinDirection() function with the pin number and the desired direction.
4. Refresh the direction of the port using Port_RefreshPortDirection() function.
5. Set the mode of a pin using Port_SetPinMode() function with the pin number and the desired mode.
6. Get the version information of the Port Driver using Port_GetVersionInfo() function.
# **Configuration**
This Port Driver doesn't have a configuration tool, so the symbolic names of each Port-Pin in the microcontroller must be defined in the source code by the user. The user also needs to configure the Port_ConfigType structure to initialize the Port Driver with the desired pins' direction, internal resistor, initial value, mode, direction changeability, and mode changeability.

# **API Service Id Macros**
- PORT_INIT_SID: service ID for PORT initialization.
- PORT_SET_PIN_DIRECTION_SID: service ID for setting pin direction.
- PORT_REFRESH_PORT_DIRECTION_SID: service ID for refreshing port direction.
- PORT_GET_VERSION_INFO_SID: service ID for getting version info.
- PORT_SET_PIN_MODE_SID: service ID for setting pin mode.

# **DET Error Codes**
- PORT_E_PARAM_PIN: DET code for invalid Port Pin ID requested.
- PORT_E_DIRECTION_UNCHANGEABLE: DET code for Port Pin not configured as changeable.
- PORT_E_PARAM_CONFIG: DET code for API Port_Init service called with wrong parameter.
- PORT_E_PARAM_INVALID_MODE: DET code for API Port_SetPinMode service called with wrong parameter Mode.
- PORT_E_MODE_UNCHANGEABLE: DET code for API Port_SetPinMode service called when mode is unchangeable.
- PORT_E_UNINIT: DET code for API service called without module initialization.
- PORT_E_PARAM_POINTER: DET Code for APIs called with a Null Pointer.

# **Data Types**
- Port_PinType: data type for the symbolic name of a port pin.
- Port_PinDirectionType: possible directions of a port pin.
- Port_PinModeType: different port pin modes.
- Port_InternalResistor: internal resistor type for PIN.
- Port_ConfigPin: structure to configure each individual PIN.
- Port_ConfigType: structure that is required for initialization API.
- Std_VersionInfoType: standard version information type.

# **Version Information**
- Module Version: 1.0.0
- AUTOSAR Version: 4.0.3
- Software Version:
    - Major Version: 1
    - Minor Version: 0
    - Patch Version: 0

# **Credits**
This Port Driver header file was created by Belal Mohamed.