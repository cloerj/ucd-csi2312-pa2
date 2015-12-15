//
//John-Marc Cloer
//

#ifndef PA2_CLUSTER_H
#define PA2_CLUSTER_H

#include "Point.h"

namespace Clustering
{
    // Creates a type that points to a point
    typedef Point *PointPtr;
    typedef struct LNode *LNodePtr;

    // Node for Linked List
    struct LNode
    {
        PointPtr p;
        LNodePtr next;
    };

    class Cluster {

    private:
        int size;           // Size of the Cluster
        LNodePtr head;      // Pointer to the Linked List Head node

    public:
        // Default Constructor
        Cluster();

        // Overload Big Three:
        Cluster(const Cluster &);                   //Copy Constructor
        Cluster &operator=(const Cluster &);        //Overloaded Assignment Operator
        ~Cluster();                                 //Destructor

        // Set functions
        void add(const PointPtr &);                 //Adder
        const PointPtr &remove(const PointPtr &);   //Remover

        //Get Functions
        int getSize() const {return size;};         //Get Size
        LNodePtr getHead() const {return head;};    //Get Head


        //Overloaded Operators

        // IO
        // - Friends
        friend std::ostream &operator<<(std::ostream &, const Cluster &);
        friend std::istream &operator>>(std::istream &, Cluster& );

        // Set-preserving operators (do not duplicate points in the space)
        // - Friends
        friend bool operator==(const Cluster &lhs, const Cluster &rhs);

        // - Members
        Cluster &operator+=(const Point &rhs); // allocate point
        Cluster &operator-=(const Point &rhs); // delete point(s) (greedy)

        // Set-destructive operators (duplicate points in the space)

        // - Friends
        friend const Cluster operator+(const Cluster &lhs, const Cluster &rhs);
        friend const Cluster operator-(const Cluster &lhs, const Cluster &rhs);

        friend const Cluster operator+(const Cluster &cluster, const PointPtr &ptr);
        friend const Cluster operator-(const Cluster &cluster, const PointPtr &ptr);

        // - Members
        Cluster &operator+=(const Cluster &rhs); // union
        Cluster &operator-=(const Cluster &rhs); // (asymmetric) difference
    };
}


#endif //PA2_CLUSTER_H
