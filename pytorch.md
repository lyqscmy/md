import torch
import torch.nn as nn
import torch.autograd as autograd

m = nn.Conv1d(10, 100, (2,60))
input = autograd.Variable(torch.randn(10, 100, 60))
output = m(input)