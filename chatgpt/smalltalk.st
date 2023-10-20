Object subclass: Vehicle [

    Vehicle class >> drive [
        ^'Driving the vehicle'
    ]

]

Vehicle subclass: Car [

    | make model |

    Car class >> make: aMake model: aModel [
        ^self new make: aMake; model: aModel; yourself
    ]

    Car >> make: aMake model: aModel [
        make := aMake.
        model := aModel.
        ^self
    ]

    Car >> drive [
        ^'Driving the ', make, ' ', model, ' car'
    ]

]

Car subclass: ElectricCar [

    | batteryCapacity |

    ElectricCar class >> make: aMake model: aModel batteryCapacity: aBatteryCapacity [
        ^self new make: aMake; model: aModel; batteryCapacity: aBatteryCapacity; yourself
    ]

    ElectricCar >> batteryCapacity: aBatteryCapacity [
        batteryCapacity := aBatteryCapacity.
        ^self
    ]

    ElectricCar >> drive [
        ^'Driving the electric ', make, ' ', model, ' car with a ', batteryCapacity asString, ' kWh battery'
    ]

]

| vehicle car electricCar |
vehicle := Vehicle new.
car := Car make: 'Toyota' model: 'Camry'.
electricCar := ElectricCar make: 'Tesla' model: 'Model S' batteryCapacity: 100.

Transcript show: (vehicle drive); cr.
Transcript show: (car drive); cr.
Transcript show: (electricCar drive); cr.
