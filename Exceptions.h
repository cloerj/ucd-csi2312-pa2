//
// John-Marc Cloer
//

#ifndef PA4_INT_EXCEPTIONS_H
#define PA4_INT_EXCEPTIONS_H

namespace Clustering {

    class Bounds {                  //Checks to see if clusters are out of bounds
    private:
        std::string name;
        Bounds(const std::string &name) : name(name) { "Bounds"; }
    public:
        std::string getName() const { return name; };
        Bounds();
        friend std::ostream &operator<<(std::ostream &, const std::string &);
    }
    
    class Clusterless {             //Checks if there are Clusters
    private:
        std::string name;
        Clusterless(const std::string &name) : name(name) {"Clusterless";}
    public:
        std::string getName() const {return name;};
        Clusterless();
        friend std::ostream &operator<<(std::ostream &, const std::string &);
    };

    class Dimensionals {            //Checks to see if there is a dimensional problem
    private:
        std::string name;
        Dimensionals(const std::string &name) : name(name) {"Dimensionals";}
    public:
        std::string getName() const {return name;};
        Dimensionals(int);
        friend std::ostream &operator<<(std::ostream &, const std::string &);    
    };

    class Empty {                   //Checks if the cluster is empty
    private:
        std::string name;
        Empty(const std::string &name) : name(name) {"Empty";}
    public:
        std::string getName() const {return name;};
        Empty();
        friend std::ostream &operator<<(std::ostream &, const std::string &);
    };
};
#endif //PA4_INT_EXCEPTIONS_H
