/**
 * Copyright (C) 2008 Meteor Liu
 *
 * This code has been released into the Public Domain.
 * You may do whatever you like with it.
 *
 * @file
 * @author Meteor Liu <meteor1113@gmail.com>
 * @date 2009-01-01
 */


#ifndef THREAD_THREAD_HPP_
#define THREAD_THREAD_HPP_


// #include <standard library headers>
#include <stdio.h>
#include <cassert>
#include <string>
#include <exception>
#include <iostream>

// #include <other library headers>

// #include "customer headers"
#include "threadimpl.hpp"


namespace thread
{

    class ThreadException : public std::exception
    {
    public:
        ThreadException(const std::string& s = "") : msg(s) {}
        virtual ~ThreadException() throw() {};

    public:
        virtual const char* what() const throw () { return msg.c_str(); }
        virtual const std::string What() const { return msg; }

    private:
        std::string msg;

    };


    /**
     * description
     */
    class Thread
    {
    public:
        explicit Thread(const std::string & name = "")
            : mName(name), mRetValue(-1), mStop(false), mAlive(false) {}
        virtual ~Thread() { if (IsAlive()) { OnLeaking(); } }

    private:
        Thread(const Thread &);
        void operator=(const Thread &);

    public:
        static void Sleep(int ms) { ThreadImpl::Sleep(ms); }
        void Start(unsigned int stackSize = DEFAULT_STACK_SIZE);
        bool WaitForEnd(int ms = WAIT_INFINITE);
        void Terminate();
        void SetStop() { mStop = true; }
        bool GetStop() const { return mStop; }
        bool IsAlive() const { return mAlive; }
        std::string GetName() const { return mName; }
        int GetId() const { return ThreadImpl::GetThreadId(mTs); }
        int GetRetValue() const { return mRetValue; }

    protected:
        virtual int Run() = 0;
        virtual void OnException(const ThreadException& e);
        virtual void OnLeaking() throw() {printf("OnLeaking\n"); }
        void SetRetValue(const int& ret) { mRetValue = ret; }
#ifdef _WIN32
        static unsigned int __stdcall ThreadFunction(void* param);
#else
        static void* ThreadFunction(void* param);
#endif

    public:
#if _MSC_VER < 1300
        enum { WAIT_INFINITE = ThreadImpl::WAIT_INFINITE };
        enum { INVALID_THREAD_ID = ThreadImpl::INVALID_THREAD_ID };
        enum { DEFAULT_STACK_SIZE = ThreadImpl::DEFAULT_STACK_SIZE };
        enum { WAIT_TIME_SLICE = ThreadImpl::WAIT_TIME_SLICE };
#elif
        static const int WAIT_INFINITE = ThreadImpl::WAIT_INFINITE;
        static const int INVALID_THREAD_ID = ThreadImpl::INVALID_THREAD_ID;
        static const size_t DEFAULT_STACK_SIZE = ThreadImpl::DEFAULT_STACK_SIZE;
        static const int WAIT_TIME_SLICE = ThreadImpl::WAIT_TIME_SLICE;
#endif

    private:
        ThreadImpl::ThreadStruct mTs; /* thread information structure */
        std::string mName;    /* The name of the thread */
        int mRetValue;
        bool mStop;
        bool mAlive;

    };


    template <typename T>
    class ThreadHolder : public Thread
    {
    public:
        ThreadHolder(T& t, const std::string & threadName = "")
            :Thread(threadName), mT(t) {}
        virtual ~ThreadHolder() {}

    protected:
        virtual int Run() { mT(); return 0; }

    private:
        T& mT;

    };


    typedef void (*TypeThreadFunction)();
    class ThreadHelper : public Thread
    {
    public:
        ThreadHelper(TypeThreadFunction tf, const std::string & threadName = "")
            :Thread(threadName), mTf(tf) {}
        virtual ~ThreadHelper() {}

    protected:
        virtual int Run() { mTf(); return 0; }

    private:
        TypeThreadFunction mTf;

    };


    inline void Thread::Start(unsigned int stackSize)
    {
        mAlive = true;
        bool res = ThreadImpl::CreateThread(mTs,
                                            ThreadFunction,
                                            stackSize,
                                            static_cast<Thread*>(this));
        if (!res)
        {
            throw ThreadException("CreateThread failed.");
        }
    }

    inline bool Thread::WaitForEnd(int ms)
    {
        int iDelta = WAIT_TIME_SLICE;
        int iTotal = ms;
        if (ms == WAIT_INFINITE)
        {
            iDelta = 0;
            iTotal = 1;
        }
        for (int i = 0; i < iTotal; i += iDelta)
        {
            if (!IsAlive())
            {
                ThreadImpl::DestroyThread(mTs);
                return true;
            }
            Sleep(WAIT_TIME_SLICE);
        }
        return false;
    }

    inline void Thread::Terminate()
    {
        ThreadImpl::TerminateThread(mTs);
        ThreadImpl::DestroyThread(mTs);
    }

    inline void Thread::OnException(const ThreadException& e)
    {
        std::cout << "Exception:" << e.What() << std::endl;
    }

#ifdef _WIN32
    inline unsigned int __stdcall Thread::ThreadFunction(void* param)
#else
    inline void* Thread::ThreadFunction(void* param)
#endif
    {
        assert(param != NULL);
        Thread* thread = (Thread*)param;
        try
        {
            int ret = thread->Run();
            thread->SetRetValue(ret);
        }
        catch (const ThreadException& ex)
        {
            thread->OnException(ex);
        }
        catch (...)
        {
            thread->OnException(ThreadException("unknown exception"));
        }
        thread->mAlive = false;
        return 0;
    }

}


#endif // THREAD_THREAD_HPP_
