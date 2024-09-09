// Copyright (c) 2005-2023 Code Synthesis.
//
// This program was generated by CodeSynthesis XSD, an XML Schema to
// C++ data binding compiler.
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License version 2 as
// published by the Free Software Foundation.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
//
// In addition, as a special exception, Code Synthesis gives permission
// to link this program with the Xerces-C++ library (or with modified
// versions of Xerces-C++ that use the same license as Xerces-C++), and
// distribute linked combinations including the two. You must obey the GNU
// General Public License version 2 in all respects for all of the code
// used other than Xerces-C++. If you modify this copy of the program, you
// may extend this exception to your version of the program, but you are
// not obligated to do so. If you do not wish to do so, delete this
// exception statement from your version.
//
// Furthermore, Code Synthesis makes a special exception for the Free/Libre
// and Open Source Software (FLOSS) which is described in the accompanying
// FLOSSE file.
//

#ifndef DIVE_TYPE_HXX
#define DIVE_TYPE_HXX

#include "diveType-fwd.hxx"

// Begin prologue.
//
//
// End prologue.

#include <xsd/cxx/config.hxx>

#if (LIBXSD_VERSION != 400002000000000L)
#error XSD runtime version mismatch
#endif

#include <xsd/cxx/pre.hxx>

#include <memory>    // ::std::unique_ptr
#include <limits>    // std::numeric_limits
#include <algorithm> // std::binary_search
#include <utility>   // std::move

#include <xsd/cxx/xml/char-utf8.hxx>

#include <xsd/cxx/tree/exceptions.hxx>
#include <xsd/cxx/tree/elements.hxx>
#include <xsd/cxx/tree/containers.hxx>
#include <xsd/cxx/tree/list.hxx>

#include <xsd/cxx/xml/dom/parsing-header.hxx>

#include "ID_TYPE.hxx"

#include "applicationdataType-fwd.hxx"

#include "informationbeforediveType-fwd.hxx"

#include "tankdataType-fwd.hxx"

#include "samplesType-fwd.hxx"

#include "informationafterdiveType-fwd.hxx"

namespace streit
{
  class diveType: public ::streit::ID_TYPE
  {
    public:
    // applicationdata
    //
    typedef ::streit::applicationdataType applicationdata_type;
    typedef ::xsd::cxx::tree::optional< applicationdata_type > applicationdata_optional;
    typedef ::xsd::cxx::tree::traits< applicationdata_type, char > applicationdata_traits;

    const applicationdata_optional&
    applicationdata () const;

    applicationdata_optional&
    applicationdata ();

    void
    applicationdata (const applicationdata_type& x);

    void
    applicationdata (const applicationdata_optional& x);

    void
    applicationdata (::std::unique_ptr< applicationdata_type > p);

    // informationbeforedive
    //
    typedef ::streit::informationbeforediveType informationbeforedive_type;
    typedef ::xsd::cxx::tree::traits< informationbeforedive_type, char > informationbeforedive_traits;

    const informationbeforedive_type&
    informationbeforedive () const;

    informationbeforedive_type&
    informationbeforedive ();

    void
    informationbeforedive (const informationbeforedive_type& x);

    void
    informationbeforedive (::std::unique_ptr< informationbeforedive_type > p);

    // tankdata
    //
    typedef ::streit::tankdataType tankdata_type;
    typedef ::xsd::cxx::tree::sequence< tankdata_type > tankdata_sequence;
    typedef tankdata_sequence::iterator tankdata_iterator;
    typedef tankdata_sequence::const_iterator tankdata_const_iterator;
    typedef ::xsd::cxx::tree::traits< tankdata_type, char > tankdata_traits;

    const tankdata_sequence&
    tankdata () const;

    tankdata_sequence&
    tankdata ();

    void
    tankdata (const tankdata_sequence& s);

    // samples
    //
    typedef ::streit::samplesType samples_type;
    typedef ::xsd::cxx::tree::optional< samples_type > samples_optional;
    typedef ::xsd::cxx::tree::traits< samples_type, char > samples_traits;

    const samples_optional&
    samples () const;

    samples_optional&
    samples ();

    void
    samples (const samples_type& x);

    void
    samples (const samples_optional& x);

    void
    samples (::std::unique_ptr< samples_type > p);

    // informationafterdive
    //
    typedef ::streit::informationafterdiveType informationafterdive_type;
    typedef ::xsd::cxx::tree::traits< informationafterdive_type, char > informationafterdive_traits;

    const informationafterdive_type&
    informationafterdive () const;

    informationafterdive_type&
    informationafterdive ();

    void
    informationafterdive (const informationafterdive_type& x);

    void
    informationafterdive (::std::unique_ptr< informationafterdive_type > p);

    // Constructors.
    //
    diveType (const id_type&,
              const informationbeforedive_type&,
              const informationafterdive_type&);

    diveType (const id_type&,
              ::std::unique_ptr< informationbeforedive_type >,
              ::std::unique_ptr< informationafterdive_type >);

    diveType (const ::xercesc::DOMElement& e,
              ::xml_schema::flags f = 0,
              ::xml_schema::container* c = 0);

    diveType (const diveType& x,
              ::xml_schema::flags f = 0,
              ::xml_schema::container* c = 0);

    virtual diveType*
    _clone (::xml_schema::flags f = 0,
            ::xml_schema::container* c = 0) const;

    diveType&
    operator= (const diveType& x);

    virtual 
    ~diveType ();

    // Implementation.
    //
    protected:
    void
    parse (::xsd::cxx::xml::dom::parser< char >&,
           ::xml_schema::flags);

    protected:
    applicationdata_optional applicationdata_;
    ::xsd::cxx::tree::one< informationbeforedive_type > informationbeforedive_;
    tankdata_sequence tankdata_;
    samples_optional samples_;
    ::xsd::cxx::tree::one< informationafterdive_type > informationafterdive_;
  };
}

#include <iosfwd>

namespace streit
{
  ::std::ostream&
  operator<< (::std::ostream&, const diveType&);
}

#include <iosfwd>

#include <xercesc/sax/InputSource.hpp>
#include <xercesc/dom/DOMDocument.hpp>
#include <xercesc/dom/DOMErrorHandler.hpp>

namespace streit
{
}

#include <xsd/cxx/post.hxx>

// Begin epilogue.
//
//
// End epilogue.

#endif // DIVE_TYPE_HXX
