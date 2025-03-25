# Notes
This will register any solution for problems that I had.  

> I'm not good with C++, so the solutions could be bad and I could be making wrong assumptions of how the language works.  

## Pointer problem
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

Have in mind that this affect how many functions in the class work.