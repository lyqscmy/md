// tag:memory model

// compiler vs hardware
g_var = 0;
for (...)
{
    ...
    g_var = ...;
    ...
}

register = 0;
for (...)
{
    ...
    register = ...;
    ...
} 
g_var = register;