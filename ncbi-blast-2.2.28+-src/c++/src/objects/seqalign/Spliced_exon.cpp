/* $Id: Spliced_exon.cpp 352019 2012-02-02 17:54:51Z grichenk $
 * ===========================================================================
 *
 *                            PUBLIC DOMAIN NOTICE
 *               National Center for Biotechnology Information
 *
 *  This software/database is a "United States Government Work" under the
 *  terms of the United States Copyright Act.  It was written as part of
 *  the author's official duties as a United States Government employee and
 *  thus cannot be copyrighted.  This software/database is freely available
 *  to the public for use. The National Library of Medicine and the U.S.
 *  Government have not placed any restriction on its use or reproduction.
 *
 *  Although all reasonable efforts have been taken to ensure the accuracy
 *  and reliability of the software and data, the NLM and the U.S.
 *  Government do not and cannot warrant the performance or results that
 *  may be obtained by using this software or data. The NLM and the U.S.
 *  Government disclaim all warranties, express or implied, including
 *  warranties of performance, merchantability or fitness for any particular
 *  purpose.
 *
 *  Please cite the author in any work or product based on this material.
 *
 * ===========================================================================
 *
 * Author:  .......
 *
 * File Description:
 *   .......
 *
 * Remark:
 *   This code was originally generated by application DATATOOL
 *   using the following specifications:
 *   'seqalign.asn'.
 */

// standard includes
#include <ncbi_pch.hpp>

// generated includes
#include <objects/seqalign/Spliced_exon.hpp>

// generated classes

BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::

// destructor
CSpliced_exon::~CSpliced_exon(void)
{
}


CRef<CSeq_interval>
CSpliced_exon::CreateRowSeq_interval(CSeq_align::TDim    row,
                                     const CSpliced_seg& seg) const
{
    CRef<CSeq_interval> ret;
    if (row != 0  &&  row != 1) {
        NCBI_THROW(CSeqalignException, eInvalidRowNumber,
                   "CSpliced_exon::CreateRowSeq_interval() - "
                   "row number must be 0 or 1 for spliced-segs.");
    }
    ret.Reset(new CSeq_interval);

    if (row == 0) {
        _ASSERT(GetProduct_start().Which() == GetProduct_end().Which());
        switch ( GetProduct_start().Which() ) {
        case CProduct_pos::e_Nucpos:
            ret->SetFrom(GetProduct_start().GetNucpos());
            ret->SetTo(GetProduct_end().GetNucpos());
            break;
        case CProduct_pos::e_Protpos:
            ret->SetFrom(GetProduct_start().GetProtpos().GetAmin());
            ret->SetTo(GetProduct_end().GetProtpos().GetAmin());
            break;
        default:
            NCBI_THROW(CSeqalignException, eInvalidAlignment,
                       "CSpliced_exon::CreateRowSeq_interval() - "
                       "start/end product-pos types do not match.");
            break;
        }
        if ( IsSetProduct_id() ) {
            ret->SetId().Assign(GetProduct_id());
        }
        else if ( seg.IsSetProduct_id() ) {
            ret->SetId().Assign(seg.GetProduct_id());
        }
        else {
            NCBI_THROW(CSeqalignException, eInvalidAlignment,
                       "CSpliced_exon::CreateRowSeq_interval() - "
                       "missing product id.");
        }
        if ( IsSetProduct_strand() ) {
            ret->SetStrand(GetProduct_strand());
        }
        else if ( seg.IsSetProduct_strand() ) {
            ret->SetStrand(seg.GetProduct_strand());
        }
    }
    else if (row == 1) {
        // Genomic
        ret->SetFrom(GetGenomic_start());
        ret->SetTo(GetGenomic_end());
        if ( IsSetGenomic_id() ) {
            ret->SetId().Assign(GetGenomic_id());
        }
        else if ( seg.IsSetGenomic_id() ) {
            ret->SetId().Assign(seg.GetGenomic_id());
        }
        else {
            NCBI_THROW(CSeqalignException, eInvalidAlignment,
                       "CSpliced_exon::CreateRowSeq_interval() - "
                       "missing genomic id.");
        }
        if ( IsSetGenomic_strand() ) {
            ret->SetStrand(GetGenomic_strand());
        }
        else if ( seg.IsSetGenomic_strand() ) {
            ret->SetStrand(seg.GetGenomic_strand());
        }
    }
    return ret;
}


END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE

/* Original file checksum: lines: 57, chars: 1735, CRC32: e5745056 */
