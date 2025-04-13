# Discussion

## Q2

##### The code seems good as is. I don't think there's more to improve it.

## Q3 & Q4

#### Why not use the library?

##### Why we may not utilize it: the question implies integer exponents and integer inputs to be used. Whereas the ```math.h``` library provides a built-in function, which is ```pow```, it takes ```double``` as the parameters, and returns ```double```. We could have explicitly converted the type of the return to ```int``` for reading purposes. It applies for the parameters as well; we could have explicitly converted from ```int``` to  ```double```. Besides all these, I made it so the machine ensures to do integer multiplication & addition.