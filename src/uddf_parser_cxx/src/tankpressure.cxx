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

#include "tankpressure.hxx"

#include "IDREF.hxx"

namespace streit
{
  // tankpressure
  //

  const tankpressure::ref_optional& tankpressure::
  ref () const
  {
    return this->ref_;
  }

  tankpressure::ref_optional& tankpressure::
  ref ()
  {
    return this->ref_;
  }

  void tankpressure::
  ref (const ref_type& x)
  {
    this->ref_.set (x);
  }

  void tankpressure::
  ref (const ref_optional& x)
  {
    this->ref_ = x;
  }

  void tankpressure::
  ref (::std::unique_ptr< ref_type > x)
  {
    this->ref_.set (std::move (x));
  }
}

#include <xsd/cxx/xml/dom/parsing-source.hxx>

namespace streit
{
  // tankpressure
  //

  tankpressure::
  tankpressure (const ::xml_schema::float_& _xsd_float__base)
  : ::xsd::cxx::tree::fundamental_base< ::xml_schema::float_, char, ::xml_schema::simple_type > (_xsd_float__base),
    ref_ (this)
  {
  }

  tankpressure::
  tankpressure (const tankpressure& x,
                ::xml_schema::flags f,
                ::xml_schema::container* c)
  : ::xsd::cxx::tree::fundamental_base< ::xml_schema::float_, char, ::xml_schema::simple_type > (x, f, c),
    ref_ (x.ref_, f, this)
  {
  }

  tankpressure::
  tankpressure (const ::xercesc::DOMElement& e,
                ::xml_schema::flags f,
                ::xml_schema::container* c)
  : ::xsd::cxx::tree::fundamental_base< ::xml_schema::float_, char, ::xml_schema::simple_type > (e, f | ::xml_schema::flags::base, c),
    ref_ (this)
  {
    if ((f & ::xml_schema::flags::base) == 0)
    {
      ::xsd::cxx::xml::dom::parser< char > p (e, false, false, true);
      this->parse (p, f);
    }
  }

  void tankpressure::
  parse (::xsd::cxx::xml::dom::parser< char >& p,
         ::xml_schema::flags f)
  {
    while (p.more_attributes ())
    {
      const ::xercesc::DOMAttr& i (p.next_attribute ());
      const ::xsd::cxx::xml::qualified_name< char > n (
        ::xsd::cxx::xml::dom::name< char > (i));

      if (n.name () == "ref" && n.namespace_ ().empty ())
      {
        this->ref_.set (ref_traits::create (i, f, this));
        continue;
      }
    }
  }

  tankpressure* tankpressure::
  _clone (::xml_schema::flags f,
          ::xml_schema::container* c) const
  {
    return new class tankpressure (*this, f, c);
  }

  tankpressure& tankpressure::
  operator= (const tankpressure& x)
  {
    if (this != &x)
    {
      static_cast< ::xsd::cxx::tree::fundamental_base< ::xml_schema::float_, char, ::xml_schema::simple_type >& > (*this) = x;
      this->ref_ = x.ref_;
    }

    return *this;
  }

  tankpressure::
  ~tankpressure ()
  {
  }
}

#include <ostream>

namespace streit
{
  ::std::ostream&
  operator<< (::std::ostream& o, const tankpressure& i)
  {
    o << static_cast< const ::xsd::cxx::tree::fundamental_base< ::xml_schema::float_, char, ::xml_schema::simple_type >& > (i);

    if (i.ref ())
    {
      o << ::std::endl << "ref: " << *i.ref ();
    }

    return o;
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

