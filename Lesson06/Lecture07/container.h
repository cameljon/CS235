//  CIS 235      Lecture 7 Container
//
#ifndef CONTAINER_H
#define CONTAINER_H
class container {
   public:
    container(void);
    container(const container &);
    container(long s, long u, const char d[]);

    ~container();

    container &setSize(long);
    container &setUsed(long);
    container &changeDesc(const char[]);

    long        getSize(void) const;
    long        getUsed(void) const;
    const char *getDesc(void) const;

    const container &operator=(const container &r);

   private:
    container &setDesc(const char[]);

    long  size, used;
    char *desc;
};
#endif