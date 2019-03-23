#include <memory>

//
// Created by 倪震洋 on 2019-03-07.
//
// 锁打印
//
#include <iostream>
#include <thread>
#include <map>

static std::mutex map_lock;
static std::map<std::ostream *, std::unique_ptr<std::mutex>> stream_locks;


// TODO START
std::ostream& os_lock(std::ostream& os) {
    map_lock.lock();
    if (!stream_locks.count(&os)) {
        stream_locks[&os] = std::make_unique<std::mutex>();
    }
    stream_locks[&os]->lock();
    return os;
}

std::ostream& os_unlock(std::ostream& os) {
    stream_locks[&os]->unlock();
    map_lock.unlock();
    return os;

}

void non_lock_output(size_t i) {
    std::cout << os_lock << "Thread " << i << " [quest 1]" << std::endl << os_unlock;
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << os_lock << "Thread " << i << " [quest 2]" << std::endl << os_unlock;
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << os_lock << "Thread " << i << " [quest 3]" << std::endl << os_unlock;
    std::cout << os_lock << "Thread " << i << " ............. " << std::endl << os_unlock;
}


void func_1_1() {
    std::cout << "Unlocked output stream" << std::endl;
    std::thread thread1(non_lock_output, 1);
    std::thread thread2(non_lock_output, 2);
    thread1.join();
    thread2.join();
}
