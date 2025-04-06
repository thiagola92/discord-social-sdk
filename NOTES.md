# Notes
This will register any solution for problems that I had.  

> I'm not good with C++, so the solutions could be bad and I could be making wrong assumptions of how the language works.  

## Optional return problem
Some methods from SDK can return `std::optional<T>` values.  
They are useful to prevent users from incorrectly using a return value (for example, a not setted value).  

I don't intend to create a class "optional" to solve this problem in GDScript, so I'm just going to return `null` in this cases. This means that the return type for this methods will have to be `Variant`.  

C++ signature:  
```C++
std::optional<std::string> State()
```

GDScript signature:  
```GDScript
Variant get_state()
```

## TODO List
Automatic extract informations from C files (classes, callbacks, enum...).  

---

Careful about methods having the same name as used in Godot (`connect()` and `disconnect()` in godot is used by signals)  

---

Parsing type should generate more types (`std::optional<std::vector<int>>`) instead of one type

---

Some classes doesn't let copying:  
```
   auto r = call->GetVADThreshold();
   auto t_r = (discordpp::VADThresholdSettings *)memalloc(sizeof(discordpp::VADThresholdSettings));
   *t_r = r;
   ```

So we change to (or find another way):
```
auto t_r = (discordpp::VADThresholdSettings *)memalloc(sizeof(discordpp::VADThresholdSettings));
*t_r = call->GetVADThreshold();
```

---

Decide where to put the `discordpp::RunCallbacks()`