# Perceptron
A simple supervised model for binary classification.

## Approach
- We have a input vector full of Neuron objects. Each neuron object is linked to the output Neuron object. By looping trought the input vector and feeding each object the actual input from the dataset we can easily make the weighted sum in the output Neuron.
- After we get the output, we update the weights using the following function: ![alt text](https://github.com/sturzamihai/unleashing-ml/tree/master/algorithms/Perceptron/images/formula)
- I took this approach because I will soon implement actual neural networks.