﻿/*
Copyright (C) 2015  xfgryujk
http://tieba.baidu.com/f?kw=%D2%BB%B8%F6%BC%AB%C6%E4%D2%FE%C3%D8%D6%BB%D3%D0xfgryujk%D6%AA%B5%C0%B5%C4%B5%D8%B7%BD

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License along
with this program; if not, write to the Free Software Foundation, Inc.,
51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*/

#pragma once
#include "DefriendDlg.h"
#include <memory>
#include <thread>


class CDefriend final
{
public:
	CDefriend(HMODULE module);
	~CDefriend();

	void Init();
	void Uninit();
	void OnConfig();

	void StartDefriend(const CString& startPage, const CString& endPage, BOOL defriendNewUsers);
	void StopDefriend();
	void DefriendThread(CString startPage, CString endPage, BOOL defriendNewUsers);
	void DoDefriend(int startPage, int endPage);


	HMODULE m_module;

	CDefriendDlg* m_defriendDlg = NULL;

	std::unique_ptr<std::thread> m_defriendThread;
	BOOL m_stopFlag = TRUE;
};
