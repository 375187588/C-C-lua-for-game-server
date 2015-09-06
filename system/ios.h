#pragma once
#include <boost/asio/io_service.hpp>
#include <boost/system/error_code.hpp>
#include "singleton.h"

#include "export.h"

typedef singleton_default<boost::asio::io_service> sios;

namespace
{
	void IOSWork() //�������������Ѿ���ɵ�io��������֮�󣬺�������;������֮�󣬾�Ҫ��ʼ�����������
	{
		boost::system::error_code ec;
		sios::instance().poll(ec);
	}
}

