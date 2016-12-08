#ifndef SJTU_VECTOR_HPP
#define SJTU_VECTOR_HPP

#include "exceptions.hpp"

#include <climits>
#include <cstddef>
#include <typeinfo>

namespace sjtu {
/**
 * a data container like std::vector
 * store data in a successive memory and support random access.
 */
template<typename T>
class vector {
protected:
    size_t Capacity,Size;
    T **data;
public:
	/**
	 * TODO
	 * a type for actions of the elements of a vector, and you should write
	 *   a class named const_iterator with same interfaces.
	 */
	/**
	 * you can see RandomAccessIterator at CppReference for help.
	 */
	class const_iterator;
	class iterator {
	private:
	    T **point;

		/**
		 * TODO add data members
		 *   just add whatever you want.
		 */
	public:
		/**
		 * return a new iterator which pointer n-next elements
		 *   even if there are not enough elements, just return the answer.
		 * as well as operator-
		 */
        iterator(T** p=NULL):point(p){}
        iterator(const iterator& rhs){point=rhs.point;}
		iterator operator+(const int &n) const {
		    iterator tmp;
		    tmp.point=point+n;
		    return tmp;
		}
		iterator operator-(const int &n) const {
			iterator tmp;
		    tmp.point=point-n;
		    return tmp;
		}
		// return th distance between two iterator,
		// if these two iterators points to different vectors, throw invalid_iterator.
		int operator-(const iterator &rhs) const {
		    if (typeid(*this).name()!= typeid(rhs).name()) throw invalid_iterator();
			return (point-rhs.point);
		}
		iterator operator+=(const int &n) {
			point+=n;
			return (*this);
		}
		iterator operator-=(const int &n) {
			point-=n;
			return (*this);
		}
		/**
		 * TODO iter++
		 */
		iterator operator++(int) {
		    iterator tmp=*this;
		    ++point;
		    return tmp;
		}
		/**
		 * TODO ++iter
		 */
		iterator& operator++() {
		    ++point;
		    return (*this);
		}
		/**
		 * TODO iter--
		 */
		iterator operator--(int) {
		    iterator tmp=*this;
		    --point;
		    return tmp;
        }
		/**
		 * TODO --iter
		 */
		iterator& operator--() {
		    --point;
		    return (*this);
        }
		/**
		 * TODO *it
		 */
		T& operator*() const{
		    return (**point);
		}
		/**
		 * a operator to check whether two iterators are same (pointing to the same memory).
		 */
		bool operator==(const iterator &rhs) const
		{
			if (typeid(*this).name() != typeid(rhs).name()) throw invalid_iterator();
			return (point==rhs.point);
		}
		bool operator==(const const_iterator &rhs) const
		{
			if (typeid(*this).name() != typeid(rhs).name()) throw invalid_iterator();
			return (point==rhs.point);
		}
		/**
		 * some other operator for iterator.
		 */
		bool operator!=(const iterator &rhs) const
		{
			if (typeid(*this).name() != typeid(rhs).name()) throw invalid_iterator();
			return (point!=rhs.point);
		}
		bool operator!=(const const_iterator &rhs) const
		{
			if (typeid(*this).name() != typeid(rhs).name()) throw invalid_iterator();
			return (point!=rhs.point);
		}

		bool operator>(const iterator &rhs) const
		{
			if (typeid(*this).name() != typeid(rhs).name()) throw invalid_iterator();
			return (point > rhs.point);
		}
		bool operator>(const const_iterator &rhs) const
		{
			if (typeid(*this).name() != typeid(rhs).name()) throw invalid_iterator();
			return (point > rhs.point);
		}

		bool operator>=(const iterator &rhs) const
		{
			if (typeid(*this).name() != typeid(rhs).name()) throw invalid_iterator();
			return (point >= rhs.point);
		}
		bool operator>=(const const_iterator &rhs) const
		{
			if (typeid(*this).name() != typeid(rhs).name()) throw invalid_iterator();
			return (point >= rhs.point);
		}

		bool operator<(const iterator &rhs) const
		{
			if (typeid(*this).name() != typeid(rhs).name()) throw invalid_iterator();
			return (point < rhs.point);
		}
		bool operator<(const const_iterator &rhs) const
		{
			if (typeid(*this).name() != typeid(rhs).name()) throw invalid_iterator();
			return (point < rhs.point);
		}

		bool operator<=(const iterator &rhs) const
		{
			if (typeid(*this).name() != typeid(rhs).name()) throw invalid_iterator();
			return (point <= rhs.point);
		}
		bool operator<=(const const_iterator &rhs) const
		{
			if (typeid(*this).name() != typeid(rhs).name()) throw invalid_iterator();
			return (point <= rhs.point);
		}
	};
	/**
	 * TODO
	 * has same function as iterator, just for a const object.
	 */
	class const_iterator {
    private:
        T **point;
    public:
        /**
		 * return a new iterator which pointer n-next elements
		 *   even if there are not enough elements, just return the answer.
		 * as well as operator-
		 */
		const_iterator(T** p = NULL) :point(p) {}
		const_iterator(const const_iterator& rhs) { point = rhs.point; }
		const_iterator operator+(const int &n) const {
		    const_iterator tmp;
		    tmp.point=point+n;
		    return tmp;
		}
		const_iterator operator-(const int &n) const {
			const_iterator tmp;
		    tmp.point=point-n;
		    return tmp;
		}
		// return th distance between two iterator,
		// if these two iterators points to different vectors, throw invalid_iterator.
		int operator-(const const_iterator &rhs) const {
			if (typeid(*this).name() != typeid(rhs).name()) throw invalid_iterator();
			return (point-rhs.point);
		}
		const_iterator operator+=(const int &n) {
			point+=n;
			return (*this);
		}
		const_iterator operator-=(const int &n) {
			point-=n;
			return (*this);
		}
		/**
		 * TODO iter++
		 */
		const_iterator operator++(int) {
		    const_iterator tmp=*this;
		    ++point;
		    return tmp;
		}
		/**
		 * TODO ++iter
		 */
		const_iterator& operator++() {
		    ++point;
		    return (*this);
		}
		/**
		 * TODO iter--
		 */
		const_iterator operator--(int) {
		    const_iterator tmp=*this;
		    --point;
		    return tmp;
        }
		/**
		 * TODO --iter
		 */
		const_iterator& operator--() {
		    --point;
		    return (*this);
        }
		/**
		 * TODO *it
		 */
		const T& operator*() const{
		    return (**point);
		}
		/**
		 * a operator to check whether two iterators are same (pointing to the same memory).
		 */
		bool operator==(const iterator &rhs) const {return (point==rhs.point);}
		bool operator==(const const_iterator &rhs) const {return (point==rhs.point);}
		/**bool operator==(const iterator &rhs) const
		{
			if (typeid(*this).name() != typeid(rhs).name()) throw invalid_iterator();
			return (point==rhs.point);
		}
		bool operator==(const const_iterator &rhs) const
		{
			if (typeid(*this).name() != typeid(rhs).name()) throw invalid_iterator();
			return (point==rhs.point);
		}
		/**
		 * some other operator for iterator.
		 */
		bool operator!=(const iterator &rhs) const
		{
			if (typeid(*this).name() != typeid(rhs).name()) throw invalid_iterator();
			return (point != rhs.point);
		}
		bool operator!=(const const_iterator &rhs) const
		{
			if (typeid(*this).name() != typeid(rhs).name()) throw invalid_iterator();
			return (point != rhs.point);
		}

		bool operator>(const iterator &rhs) const
		{
			if (typeid(*this).name() != typeid(rhs).name()) throw invalid_iterator();
			return (point > rhs.point);
		}
		bool operator>(const const_iterator &rhs) const
		{
			if (typeid(*this).name() != typeid(rhs).name()) throw invalid_iterator();
			return (point > rhs.point);
		}

		bool operator>=(const iterator &rhs) const
		{
			if (typeid(*this).name() != typeid(rhs).name()) throw invalid_iterator();
			return (point >= rhs.point);
		}
		bool operator>=(const const_iterator &rhs) const
		{
			if (typeid(*this).name() != typeid(rhs).name()) throw invalid_iterator();
			return (point >= rhs.point);
		}

		bool operator<(const iterator &rhs) const
		{
			if (typeid(*this).name() != typeid(rhs).name()) throw invalid_iterator();
			return (point < rhs.point);
		}
		bool operator<(const const_iterator &rhs) const
		{
			if (typeid(*this).name() != typeid(rhs).name()) throw invalid_iterator();
			return (point < rhs.point);
		}

		bool operator<=(const iterator &rhs) const
		{
			if (typeid(*this).name() != typeid(rhs).name()) throw invalid_iterator();
			return (point <= rhs.point);
		}
		bool operator<=(const const_iterator &rhs) const
		{
			if (typeid(*this).name() != typeid(rhs).name()) throw invalid_iterator();
			return (point <= rhs.point);
		}
	};
	/**
	 * TODO Constructs
	 * Atleast three: default constructor, copy constructor and a constructor for std::vector
	 */
	vector():Size(0),Capacity(2){
		data=new T*[Capacity];
		if (!data) throw runtime_error();
	}
	vector(const vector &other)
	{
	    Capacity=other.Capacity;
	    Size=other.Size;
		data = new T*[Capacity];
		if (!data) throw runtime_error();
	    for (size_t i=0;i<Size;++i) data[i]=new T(*(other.data[i]));
	}
	/**
	 * TODO Destructor
	 */
	~vector() {
		for (size_t i = 0; i < Size; ++i) delete data[i];
		delete[] data;
	}
	/**
	 * TODO Assignment operator
	 */
	vector &operator=(const vector &other)
	{
	    if (this==&other) return (*this);
		for (size_t i = 0; i < Size; ++i) delete[] data[i];
		delete[] data;
	    Capacity=other.Capacity;
	    Size=other.Size;
		data = new T*[Capacity];
	    for (size_t i=0;i<Size;++i) data[i]=new T(*(other.data[i]));
	    return (*this);
	}
	/**
	 * assigns specified element with bounds checking
	 * throw index_out_of_bound if pos is not in [0, size)
	 */
	T & at(const size_t &pos)
	{
	    if (pos<0 || pos>Size) throw index_out_of_bound();
	    return *data[pos];
	}
	const T & at(const size_t &pos) const
	{
	    if (pos<0 || pos>Size) throw index_out_of_bound();
	    return *data[pos];
	}
	/**
	 * assigns specified element with bounds checking
	 * throw index_out_of_bound if pos is not in [0, size)
	 * !!! Pay attentions
	 *   In STL this operator does not check the boundary but I want you to do.
	 */
	T & operator[](const size_t &pos) {return *data[pos];}
	const T & operator[](const size_t &pos) const {return *data[pos];}
	/**
	 * access the first element.
	 * throw container_is_empty if size == 0
	 */
	const T & front() const
	{
	    if (Size==0) throw container_is_empty();
	    return *data[0];
	}
	/**
	 * access the last element.
	 * throw container_is_empty if size == 0
	 */
	const T & back() const
	{
	    if (Size==0) throw container_is_empty();
	    return *data[Size-1];
	}
	/**
	 * returns an iterator to the beginning.
	 */
	iterator begin() {return iterator(data);}
	const const_iterator cbegin() const {return const_iterator(data);}
	/**
	 * returns an iterator to the end.
	 */
	iterator end() {return (iterator(data)+Size);}
	const const_iterator cend() const {return (const_iterator(data + Size));}
	/**
	 * checks whether the container is empty
	 */
	bool empty() const {return (Size==0);}
	/**
	 * returns the number of elements
	 */
	size_t size() const {return Size;}
	/**
	 * returns the number of elements that can be held in currently allocated storage.
	 */
	size_t capacity() const {return Capacity;}
	/**
	 * clears the contents
	 */
	void clear()
	{
		for (size_t i = 0; i < Size; ++i) delete data[i];
		Size=0;
	}
	void doubleSpace()
	{
		Capacity *= 2;
		T **tmp = new T*[Capacity];
		if (!tmp) throw runtime_error();
		for (size_t i = 0; i<Size; ++i) tmp[i] = new T(*data[i]);
		for (size_t i = 0; i < Size; ++i) delete data[i];
		delete[] data;
		data = tmp;
	}
	/**
	* inserts value before pos
	* returns an iterator pointing to the inserted value.
	*/
	iterator insert(iterator pos, const T &value) {
	    if (pos<iterator(data) || pos-begin()>Size) throw invalid_iterator();
	    if (Size==Capacity)
	    {
			doubleSpace();
	    }
	    int position=pos-data, i;
	    for (i = Size - 1; i >= position; --i) data[i+1]=data[i];
	    data[position]=new T(value);
	    ++Size;
	    return (iterator(data+position));
	}
	/**
	 * inserts value at index ind.
	 * after inserting, this->at(ind) == value is true
	 * returns an iterator pointing to the inserted value.
	 * throw index_out_of_bound if ind > size (in this situation ind can be size because after inserting the size will increase 1.)
	 */
	iterator insert(const size_t &ind, const T &value) {
	    if (ind < 0 || ind > Size) throw index_out_of_bound();
	    if (Size==Capacity)
	    {
			doubleSpace();
	    }
	    int i;
		for (i = Size ; i > ind; --i) data[i] = data[i - 1];
	    data[ind]=new T(value);
	    ++Size;
	    return (iterator(data+ind));
    }
	/**
	 * removes the element at pos.
	 * return an iterator pointing to the following element.
	 * If the iterator pos refers the last element, the end() iterator is returned.
	 */
	iterator erase(iterator pos) {
	    if (pos<iterator(data) || pos-begin()>=Size) throw invalid_iterator();
	    int position=pos-data, i;
		delete data[position];
	    for (i=position;i<Size-1;++i) data[i]=data[i+1];
		data[--Size] = NULL;
	    return (iterator(data+position));
	}
	/**
	 * removes the element with index ind.
	 * return an iterator pointing to the following element.
	 * throw index_out_of_bound if ind >= size
	 */
	iterator erase(const size_t &ind) {
	    if (ind<0 || ind>=Size) throw index_out_of_bound();
	    int i;
		delete data[ind];
	    for (i=ind;i<Size-1;++i) data[i]=data[i+1];
	    --Size;
		data[Size] = NULL;
	    return (iterator(data+ind));
    }
	/**
	 * adds an element to the end.
	 */
	void push_back(const T &value)
	{
	    if (Size==Capacity)
	    {
			doubleSpace();
	    }
	    data[Size]=new T(value);
	    ++Size;
	}
	/**
	 * remove the last element from the end.
	 * throw container_is_empty if size() == 0
	 */
	void pop_back()
	{
	    if (Size==0) throw container_is_empty();
		delete data[Size-1];
	    --Size;
	}

};


}

#endif
