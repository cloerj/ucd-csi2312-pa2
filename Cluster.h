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

    // Node for a singly-linked List
    struct LNode
    {
        PointPtr p;        //This is to be the m_Head according to the instructions
        LNodePtr next;
    };

    class Cluster {

    private:
        int size;             // Size of the Cluster
        LNodePtr m_Head;      // Pointer to the Linked List m_Head node
        int dimensions;       // Dimensions of the points
        bool valid;           // Is it valid?
        int __id;             // Id's!
        Point __centroid;     // Point Centroids
    public:
        //Move Class
        class Move {
        private:
            Cluster *_from;
            Cluster *_to;
            PointPtr point;
        public:
            Move(const PointPtr &ptr, Cluster *from, Cluster *to) : _from(from), _to(to), point(ptr) {};
            void perform();
        };

        // Default Constructor
        Cluster();
        Cluster(int);

        // Overload Big Three:
        Cluster(const Cluster &);                   //Copy Constructor
        Cluster &operator=(const Cluster &);        //Overloaded Assignment Operator
        ~Cluster();                                 //Destructor

        // Set functions
        void add(const PointPtr &);                 // Adder
        const PointPtr &remove(const PointPtr &);   // Remover
        void removeAfter(LNodePtr lastNode);         // Removes lastNode->next
        void clear();                               // deletes a cluster
        void setCent(const Point &p) {__centroid = p; valid = true;}
        void compCent();                            // computes the centroid
        void setValid(bool isValid) {valid = isValid;}   // sets validity of a cluster
        static int idGen();                         // cluster id's!



        //Get Functions
        int getSize() const {return size;};             //Get Size
        LNodePtr getm_Head() const {return m_Head;};    //Get m_Head
        Point getCent() const {return __centroid;}      //Get Centroid
        bool isCentValid() const {return valid;}        //Centroid Validity Checker
        int getId() const {return __id;}                //Get id
        void pickPoints(unsigned int k,  Point**);            //Chooses points for initial centroids
        double twoClusDist() const;                     //The distance between two centroids
        friend double twoClusDist(const Cluster &, const Cluster &); //The distance between points of two different clusters
        int getClusPairs();                             //The number of pairs in a cluster
        friend double twoClusPairs(const Cluster &, const Cluster &);    //The number of pairs in two clusters

        //Find Functions
        const LNodePtr findPointPtr(const PointPtr) const;      //Finds PointPtr
        bool contains(const PointPtr &ptr) const;               //Finds if PointPtr is inside
        const LNodePtr findPoint(Point) const;                  //Finds a point


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
