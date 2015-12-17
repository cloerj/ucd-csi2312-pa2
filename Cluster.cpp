//
//John-Marc Cloer
//

#include <iostream>
#include <iomanip>
#include <cmath>
#include <limits>
#include "Point.h"
#include "Cluster.h"


namespace Clustering
{
	void Cluster::Move::perform()
	{
		PointPtr p = _from->remove(point);
		_to->add(p);
	}

	// Default Constructor
	//      Setting the default value to zero and the pointer is null since it's not yet pointing to anything
	Cluster::Cluster()
	{
		size = 0;
		m_Head = NULL;
		__centroid = 0;
	}

	Cluster::Cluster(int dimens):
		size(0),
		dimensions(dimens),
		__centroid(dimensions),
		__id(idGen()),
		m_Head(NULL){}


	// Copy Constructor
	Cluster::Cluster(const Cluster &ikeCluster): __centroid(Cluster().dimensions)
	{
		dimensions = ikeCluster.dimensions;
		valid = ikeCluster.valid;
		__id = ikeCluster.__id;

		// Just in case the copied cluster is empty
		if (ikeCluster.m_Head == NULL)
		{
			return;
		}

		LNodePtr node;
		LNodePtr clusterPtr = ikeCluster.m_Head;

		if (clusterPtr != NULL)
		{
			clusterPtr = clusterPtr->next;
			node = new LNode;

			if (clusterPtr == ikeCluster.m_Head)
			{
				m_Head = node;
			}
			node->p = clusterPtr->p;
		}
	}

	// Overloaded assignment operator
	Cluster &Cluster::operator=(const Cluster &ikeCluster)
	{
		if (m_Head != NULL)
		{
			// Dealocating memory
			Cluster *deallocateCluster = this;
			Cluster();
			deallocateCluster->~Cluster();
		}

		else if (ikeCluster.m_Head == NULL)
		{
			std::cout << "This cluster is empty.";
			return *this;
		}

		else
		{
			LNodePtr PtrNode = ikeCluster.m_Head;

			while (PtrNode != NULL)
			{
				add(PtrNode->p);
				PtrNode = PtrNode->next;
			}
		}
		return *this;
	}

	// destructor
	Cluster::~Cluster()
	{
		while (m_Head != NULL)
		{
			LNodePtr destroyNode = m_Head;
			m_Head = m_Head->next;
			size--;
			delete destroyNode;
		}
		delete m_Head;
	}

	// Add function
	void Cluster::add(const PointPtr& ptrp)
	{
		if(ptrp == NULL)
		{
			return;
		}

		LNodePtr m_Current = m_Head;

		LNodePtr aNewPoint = new LNode;
		aNewPoint->p = ptrp;
		aNewPoint->next = m_Current;
		m_Head = aNewPoint;
		size++;
	}

	// Remove function
	const PointPtr &Cluster::remove(const PointPtr &ptr)
	{
		LNodePtr m_Current = m_Head;
		LNodePtr m_Last = m_Current;

		if (m_Current == NULL)
		{
			return NULL;
		}

		if (m_Head->p == ptr)
		{
			LNodePtr destroyNode = m_Head;
			m_Head = m_Head->next;

			PointPtr &destroyedNode = destroyNode->p;

			size--;
			delete destroyNode;

			return destroyedNode;
		}

		while (m_Current != NULL)
		{
			m_Last = m_Current;
			m_Current = m_Current->next;
		}

		if (m_Current == NULL)
		{
			return NULL;
		}
	}

	void Cluster::removeAfter(LNodePtr preNode)
	{
		if (preNode != NULL)
		{
			setValid(false);
			LNodePtr tempNode = preNode->next;
			LNodePtr nextNode = tempNode->next;
			if (preNode->next == m_Head)
				m_Head = nextNode;
			else
				tempNode->next = nextNode;
			delete tempNode;
			size--;
		}
		else
		{
			return;
		}
	}

	//Clear function
	void Cluster::clear()
	{
		LNodePtr currNode = m_Head;
		LNodePtr next = NULL;

		//Remove Nodes
		while(currNode != NULL)
		{
			currNode = next;
			next = currNode->next;
			delete currNode;
		}

		size = 0;
		m_Head = NULL;
		setValid(false);
	}

	void Cluster::compCent()
	{
		if (size != 0)
		{
			LNodePtr headNode = m_Head;
			int dim = m_Head->p->getDims();
			Point adder(dim);
			for (headNode != NULL)
			{
				headNode = headNode->next;
				adder += (*headNode->p / size);
			}
			__centroid = adder;
			setValid(true);
		}
		else
		{
			for (int i = 1; i < dimensions + 1; i++)
				__centroid[i] = std::numeric_limits<double>::max();
			setValid(true);
			return;
		}
	}

	int Cluster::idGen()
	{
		int id = 1;
		id++;
		return id;
	}

	void Cluster::pickPoints(unsigned int k,  Point** array)
	{
		LNodePtr point = m_Head;
		int h;
		int j;
		int l = 1;
		int m = k - 1;

		if (k != 1)
		{
			if (size < k)
			{
				h = 1;
				j = size;
			}
			else
			{
				h = size / (k-l);
				j = k;
			}
			for(int i = 0; i < j; i++)
			{
				array[i] = point->p;
				point = point->next;
				if(m_Head == NULL)
				{
					return;
				}
			}
			while (m_Head->next != NULL)
			{
				m_Head = m_Head->next;
			}
			if (size >= k)
			{
				array[m] = point->p;
			}

		}
		else
		{
			array[0] = point->p;
			return;
		}
	}

	double Cluster::twoClusDist() const
	{
		double distance;
		LNodePtr justAnotherNode = m_Head;
		LNodePtr andAnotherNode;
		int j = getSize() - 1;

		for(int i = 0; i < j; i++)
		{
			andAnotherNode = justAnotherNode->next;
			if(andAnotherNode != NULL)
			{
				andAnotherNode = andAnotherNode->next;
				distance = justAnotherNode->p->distanceTo(*andAnotherNode->p);
			}
			justAnotherNode = justAnotherNode->next;
		}
		return distance;
	}

	double Cluster::twoClusDist(const Cluster &var1, const Cluster &var2)
	{
		double distance2;
		LNodePtr justAnotherNode = m_Head;
		LNodePtr andAnotherNode;
		int j = getSize() - 1;

		for(int i = 0; i < j; i++)
		{
			andAnotherNode = justAnotherNode->next;
			if(andAnotherNode != NULL)
			{
				andAnotherNode = andAnotherNode->next;
				distance2 = justAnotherNode->p->distanceTo(*andAnotherNode->p);
			}
			justAnotherNode = justAnotherNode->next;
		}
		return distance2;
	}

	int Cluster::getClusPairs()
	{
		int newSize;
		newSize = getSize();
		newSize = newSize * (newSize - 1);
		newSize = newSize / 2;

		return newSize;
	}

	double Cluster::twoClusPairs(const Cluster &var1, const Cluster &var2)
	{
		int newerSize;
		newerSize = var1.getSize();
		newerSize = newerSize * var2.getSize();
		return newerSize;
	}

	//Find Functions
	const LNodePtr Cluster::findPointPtr(const PointPtr unendingPoint) const
	{
		LNodePtr myMillionthNode = m_Head;

		if (myMillionthNode->p == unendingPoint)
		{
			LNodePtr anotherTempNode = new LNode;
			anotherTempNode->next = myMillionthNode;
			return anotherTempNode;
		}
	}

	// Equality operator
	bool operator==(const Cluster &lhs, const Cluster &rhs)
	{
		if(rhs.getSize() == lhs.getSize())
		{
			return true;
		}

		while (lhs.m_Head != NULL)
		{
			if(*(rhs.m_Head->p) == *(lhs.m_Head->p))
			{
				return true;
			}
			else
			{
				//These are only in here to fix an error I kept getting
				LNodePtr m_LHS = lhs.m_Head;
				LNodePtr m_RHS = rhs.m_Head;

				m_LHS = m_LHS->next;
				m_RHS = m_RHS->next;
			}
		}

		return false;
	}


	// Addition operator
	const Cluster operator+(const Cluster &cluster, const PointPtr &ptr)
	{
		Cluster addPointCluster(cluster);
		addPointCluster.add(ptr);
		return addPointCluster;
	}

	// Subtraction operator
	const Cluster operator-(const Cluster &cluster, const PointPtr &ptr)
	{
		Cluster subPointCluster(cluster);
		subPointCluster.remove(ptr);
		return subPointCluster;
	}

	// Compound Addition Operator
	Cluster &Cluster::operator+=(const Point &point)
	{
		PointPtr newPoint = new Point(point.getDims());
		add(newPoint);
		return *this;
	}

	// Compound Subtraction Operator
	Cluster &Cluster::operator-=(const Point &point)
	{
		PointPtr destroyPoint = new Point(point.getDims());
		LNodePtr m_Current = this->getm_Head();
		while(m_Current != NULL)
		{
			if (*destroyPoint == *(m_Current->p))
			{
				destroyPoint = m_Current->p;
				remove(destroyPoint);
				break;
			}
			else
			{
				m_Current = m_Current->next;
			}
		}
		return *this;
	}

	// Addition operator
	const Cluster operator+(const Cluster &lhs, const Cluster &rhs)
	{
		//Variables for later
		Cluster clusterU;
		LNodePtr lHead = lhs.getm_Head();
		LNodePtr rHead = rhs.getm_Head();

		if(lhs.getSize() == 0)
		{
			return lhs;
		}
		if(rhs.getSize() == 0)
		{
			return rhs;
		}
		if(rhs.getSize() <= lhs.getSize())
		{
			while (rHead != NULL)
			{
				while (*(lHead->p) == *(rHead->p))
				{
					clusterU.add(lHead->p);
				}
				rHead = rHead->next;
			}
			while (lHead->next != NULL)
			{
				clusterU.add(lHead->p);
				lHead = lHead->next;
			}
		}
	}


	// Overloaded addition operator
	const Cluster operator-(const Cluster &lhs, const Cluster &rhs)
	{
		Cluster intersection = lhs;
		intersection -= rhs;
		return intersection;
	}

	std::istream &operator>>(std::istream &iStream, Clustering::Cluster& cluster)
	{
		// for (int i = 0; i < point.getDims(); i++)
		//{
		//    iStream >> point.values[i];
		//}
		//return iStream;
	}

	Cluster &Cluster::operator+=(const Cluster &rhs)
	{
		//Cluster plusEqu = rhs;
		//plusEqu += rhs;
		//return plusEqu;
	}

	Cluster &Cluster::operator-=(const Cluster &rhs)
	{
		//Cluster minEqu = rhs;
		//minEqu -= rhs;
		//return minEqu;
	}

	std::ostream &operator<<(std::ostream &oStream, const Cluster &cluster)
	{
		LNodePtr clustHead = cluster.getm_Head();

		while (clustHead != NULL)
		{
			clustHead->p->pointToConsole();
			oStream << "," << " ";
			clustHead = clustHead->next;
		}
		if (clustHead == NULL)
		{
			oStream << "The linked list is empty Brah...";
			return oStream;
		}
	}
}
