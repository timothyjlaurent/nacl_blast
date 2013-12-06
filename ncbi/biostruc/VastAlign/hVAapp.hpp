#ifndef _VAapp_HPP
#define _VAapp_HPP

/*
 * $Id: hVAapp.hpp,v 1.1 2005/07/26 16:25:22 chenj Exp $
 *
 * ===========================================================================
 *
 *                            PUBLIC DOMAIN NOTICE
 *            National Center for Biotechnology Information (NCBI)
 *
 *  This software/database is a "United States Government Work" under the
 *  terms of the United States Copyright Act.  It was written as part of
 *  the author's official duties as a United States Government employee and
 *  thus cannot be copyrighted.  This software/database is freely available
 *  to the public for use. The National Library of Medicine and the U.S.
 *  Government do not place any restriction on its use or reproduction.
 *  We would, however, appreciate having the NCBI and the author cited in
 *  any work or product based on this material
 *
 *  Although all reasonable efforts have been taken to ensure the accuracy
 *  and reliability of the software and data, the NLM and the U.S.
 *  Government do not and cannot warrant the performance or results that
 *  may be obtained by using this software or data. The NLM and the U.S.
 *  Government disclaim all warranties, express or implied, including
 *  warranties of performance, merchantability or fitness for any particular
 *  purpose.
 *
 * ===========================================================================
 *
 * Author: Jie Chen
 *
 * $Log: hVAapp.hpp,v $
 * Revision 1.1  2005/07/26 16:25:22  chenj
 * source for vastalign.cgi
 *
 *
 */

#include <cgi/ncbicgir.hpp>
#include <cgi/cgiapp.hpp>
#include <cgi/ncbicgir.hpp>
#include <cgi/ncbires.hpp>

using namespace ncbi;

BEGIN_NCBI_SCOPE

// class CVSApp

class CVAApp : public CCgiApplication 
{

 public:

	virtual void Init(void); 
	virtual void Exit(void);
	virtual CNcbiResource* LoadResource(void);
	virtual int ProcessRequest(CCgiContext& context);
};

END_NCBI_SCOPE

#endif
