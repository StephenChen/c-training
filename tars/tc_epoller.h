//
// Created by Administrator on 2022/5/26.
//

#ifndef __TC_EPOLLER_H_
#define __TC_EPOLLER_H_

#include <sys/epoll.h>
#include <cassert>

namespace tars {

    /**
     * epoller操作类，已经默认采用了EPOLLET方式做触发
     */
    class TC_Epoller {
    public:

        /**
         * 构造函数.
         *
         * @param bEt 默认是ET模式，当状态发生变化的时候才获得通知
         */
        TC_Epoller(bool bEt = true);

        /**
         * 析构函数.
         */
        ~TC_Epoller();

        /**
         * 生成epoll句柄.
         *
         * @param max_connections epoll服务需要支持的最大连接数
         */
        void create(int max_connections);

        /**
         * 添加监听句柄.
         *
         * @param fd 句柄
         * @param data 辅助的数据, 可以后续在epoll_event中获取到
         * @param event 需要监听的事件EPOLLIN|EPOLLOUT
         */
        void add(int fd, long long data, __uint32_t event);

        /**
         * 修改句柄事件.
         *
         * @param fd    句柄
         * @param data  辅助的数据, 可以后续在epoll_event中获取到
         * @param event 需要监听的事件EPOLLIN|EPOLLOUT
         */
        void mod(int fd, long long data, __uint32_t event);

        /**
         * 删除句柄事件.
         *
         * @param fd    句柄
         * @param data  辅助的数据, 可以后续在epoll_event中获取到
         * @param event 需要监听的事件EPOLLIN|EPOLLOUT
         */
        void del(int fd, long long data, __uint32_t event);

        /**
         * 等待时间.
         *
         * @param millsecond 毫秒
         * @return 有事件触发的句柄数
         */
        int wait(int millsecond);

        /**
         * 获取被触发的事件.
         *
         * @param i
         * @return struct epoll_event&被触发的事件
         */
        struct epoll_event &get(int i) {
            assert(_pevs != 0);
            return _pevs[i];
        }

    protected:

        /**
         * 控制epoll，将EPOLL设为边缘触发EPOLLET模式
         *
         * @param fd 句柄，在create函数时被赋值
         * @param data 辅助的数据, 可以后续在epoll_event中获取到
         * @param event 需要监听的事件
         * @param op EPOLL_CTL_ADD： 注册新的fd到epfd中；
         *              EPOLL_CTL_MOD：修改已经注册的fd的监听事件；
         *              EPOLL_CTL_DEL：从epfd中删除一个fd；
         */
        void ctrl(int fd, long long data, __uint32_t event, int op);

    protected:

        /**
         * epoll
         */
        int _iEpollfd;

        /**
         * 最大连接数
         */
        int _max_connections;

        /**
         * 事件集
         */
        struct epoll_event *_pevs;

        /**
         * 是否是ET模式
         */
        bool _et;
    };
}

#endif //__TC_EPOLLER_H_
