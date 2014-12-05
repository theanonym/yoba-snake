#ifndef SINGLETON_HPP
#define SINGLETON_HPP

template <typename T>
class Singleton
{
public:
   static inline T & get()
   {
      static T instance;
      return instance;
   }

protected:
   Singleton() {}
   virtual ~Singleton() {}

private:
   Singleton(const Singleton & copy) = delete;
};


#endif // SINGLETON_HPP
