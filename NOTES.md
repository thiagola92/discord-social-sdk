# Notes
This will register any solution for problems that I had.  

> I'm not good with C++, so the solutions could be bad and I could be making wrong assumptions of how the language works.  

## No empty constructors problem
Some classes don't have an empty constructor, which means that we can't have a property like:  

```C++
   private:
       discordpp::XXXXX xxxxx;
```

Because this would be the same as doing:  

```C++
   private:
       discordpp::XXXXX xxxxx = discordpp::XXXXX();
```

They don't have empty constructor because normally their value would come from another function, for example:  

```C++
   discordpp::XXXXX xxxxx = yyyyy->CreateXXXXX();
```

To solve this, we need to make our property a pointer:  

```C++
   private:
       discordpp::XXXXX *xxxxx;
```

Have in mind that this affect how many methods in the class work.

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

## New memory
All the following cases assume that class `DiscordXXXXX` property is a pointer, otherwise you could just copy to your property using `=` (equal operator).  

If you receive a reference to a `discordpp:XXXXX` object:  
```C++
auto x = memnew(DiscordXXXXX{ &xxxxx });
```

If you receive a pointer to a `discordpp:XXXXX` object:  
```C++
auto x = memnew(DiscordXXXXX{ xxxxx });
```

If you receive a copy of a `discordpp:XXXXX` object:
```C++
auto t = (discordpp::XXXXX *)memalloc(sizeof(discordpp::XXXXX));
*t = CreateXXXXX();
auto x = memnew(DiscordXXXXX(t));
```