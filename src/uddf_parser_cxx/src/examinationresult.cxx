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

// Begin prologue.
//
//
// End prologue.

#include <xsd/cxx/pre.hxx>

#include "examinationresult.hxx"

namespace streit
{
  // examinationresult
  //

  examinationresult::
  examinationresult (value v)
  : ::xml_schema::string (_xsd_examinationresult_literals_[v])
  {
  }

  examinationresult::
  examinationresult (const char* v)
  : ::xml_schema::string (v)
  {
  }

  examinationresult::
  examinationresult (const ::std::string& v)
  : ::xml_schema::string (v)
  {
  }

  examinationresult::
  examinationresult (const ::xml_schema::string& v)
  : ::xml_schema::string (v)
  {
  }

  examinationresult::
  examinationresult (const examinationresult& v,
                     ::xml_schema::flags f,
                     ::xml_schema::container* c)
  : ::xml_schema::string (v, f, c)
  {
  }

  examinationresult& examinationresult::
  operator= (value v)
  {
    static_cast< ::xml_schema::string& > (*this) = 
    ::xml_schema::string (_xsd_examinationresult_literals_[v]);

    return *this;
  }
}

#include <xsd/cxx/xml/dom/parsing-source.hxx>

namespace streit
{
  // examinationresult
  //

  examinationresult::
  examinationresult (const ::xercesc::DOMElement& e,
                     ::xml_schema::flags f,
                     ::xml_schema::container* c)
  : ::xml_schema::string (e, f, c)
  {
    _xsd_examinationresult_convert ();
  }

  examinationresult::
  examinationresult (const ::xercesc::DOMAttr& a,
                     ::xml_schema::flags f,
                     ::xml_schema::container* c)
  : ::xml_schema::string (a, f, c)
  {
    _xsd_examinationresult_convert ();
  }

  examinationresult::
  examinationresult (const ::std::string& s,
                     const ::xercesc::DOMElement* e,
                     ::xml_schema::flags f,
                     ::xml_schema::container* c)
  : ::xml_schema::string (s, e, f, c)
  {
    _xsd_examinationresult_convert ();
  }

  examinationresult* examinationresult::
  _clone (::xml_schema::flags f,
          ::xml_schema::container* c) const
  {
    return new class examinationresult (*this, f, c);
  }

  examinationresult::value examinationresult::
  _xsd_examinationresult_convert () const
  {
    ::xsd::cxx::tree::enum_comparator< char > c (_xsd_examinationresult_literals_);
    const value* i (::std::lower_bound (
                      _xsd_examinationresult_indexes_,
                      _xsd_examinationresult_indexes_ + 2,
                      *this,
                      c));

    if (i == _xsd_examinationresult_indexes_ + 2 || _xsd_examinationresult_literals_[*i] != *this)
    {
      throw ::xsd::cxx::tree::unexpected_enumerator < char > (*this);
    }

    return *i;
  }

  const char* const examinationresult::
  _xsd_examinationresult_literals_[2] =
  {
    "passed",
    "failed"
  };

  const examinationresult::value examinationresult::
  _xsd_examinationresult_indexes_[2] =
  {
    ::streit::examinationresult::failed,
    ::streit::examinationresult::passed
  };
}

#include <ostream>

namespace streit
{
  ::std::ostream&
  operator<< (::std::ostream& o, examinationresult::value i)
  {
    return o << examinationresult::_xsd_examinationresult_literals_[i];
  }

  ::std::ostream&
  operator<< (::std::ostream& o, const examinationresult& i)
  {
    return o << static_cast< const ::xml_schema::string& > (i);
  }
}

#include <istream>
#include <xsd/cxx/xml/sax/std-input-source.hxx>
#include <xsd/cxx/tree/error-handler.hxx>

namespace streit
{
}

#include <xsd/cxx/post.hxx>

// Begin epilogue.
//
//
// End epilogue.

