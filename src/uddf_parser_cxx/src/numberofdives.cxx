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

#include "numberofdives.hxx"

namespace streit
{
  // numberofdives
  //

  const numberofdives::startdate_type& numberofdives::
  startdate () const
  {
    return this->startdate_.get ();
  }

  numberofdives::startdate_type& numberofdives::
  startdate ()
  {
    return this->startdate_.get ();
  }

  void numberofdives::
  startdate (const startdate_type& x)
  {
    this->startdate_.set (x);
  }

  void numberofdives::
  startdate (::std::unique_ptr< startdate_type > x)
  {
    this->startdate_.set (std::move (x));
  }

  const numberofdives::enddate_type& numberofdives::
  enddate () const
  {
    return this->enddate_.get ();
  }

  numberofdives::enddate_type& numberofdives::
  enddate ()
  {
    return this->enddate_.get ();
  }

  void numberofdives::
  enddate (const enddate_type& x)
  {
    this->enddate_.set (x);
  }

  void numberofdives::
  enddate (::std::unique_ptr< enddate_type > x)
  {
    this->enddate_.set (std::move (x));
  }

  const numberofdives::dives_type& numberofdives::
  dives () const
  {
    return this->dives_.get ();
  }

  numberofdives::dives_type& numberofdives::
  dives ()
  {
    return this->dives_.get ();
  }

  void numberofdives::
  dives (const dives_type& x)
  {
    this->dives_.set (x);
  }
}

#include <xsd/cxx/xml/dom/parsing-source.hxx>

namespace streit
{
  // numberofdives
  //

  numberofdives::
  numberofdives (const startdate_type& startdate,
                 const enddate_type& enddate,
                 const dives_type& dives)
  : ::xml_schema::type (),
    startdate_ (startdate, this),
    enddate_ (enddate, this),
    dives_ (dives, this)
  {
  }

  numberofdives::
  numberofdives (const numberofdives& x,
                 ::xml_schema::flags f,
                 ::xml_schema::container* c)
  : ::xml_schema::type (x, f, c),
    startdate_ (x.startdate_, f, this),
    enddate_ (x.enddate_, f, this),
    dives_ (x.dives_, f, this)
  {
  }

  numberofdives::
  numberofdives (const ::xercesc::DOMElement& e,
                 ::xml_schema::flags f,
                 ::xml_schema::container* c)
  : ::xml_schema::type (e, f | ::xml_schema::flags::base, c),
    startdate_ (this),
    enddate_ (this),
    dives_ (this)
  {
    if ((f & ::xml_schema::flags::base) == 0)
    {
      ::xsd::cxx::xml::dom::parser< char > p (e, false, false, true);
      this->parse (p, f);
    }
  }

  void numberofdives::
  parse (::xsd::cxx::xml::dom::parser< char >& p,
         ::xml_schema::flags f)
  {
    while (p.more_attributes ())
    {
      const ::xercesc::DOMAttr& i (p.next_attribute ());
      const ::xsd::cxx::xml::qualified_name< char > n (
        ::xsd::cxx::xml::dom::name< char > (i));

      if (n.name () == "startdate" && n.namespace_ ().empty ())
      {
        this->startdate_.set (startdate_traits::create (i, f, this));
        continue;
      }

      if (n.name () == "enddate" && n.namespace_ ().empty ())
      {
        this->enddate_.set (enddate_traits::create (i, f, this));
        continue;
      }

      if (n.name () == "dives" && n.namespace_ ().empty ())
      {
        this->dives_.set (dives_traits::create (i, f, this));
        continue;
      }
    }

    if (!startdate_.present ())
    {
      throw ::xsd::cxx::tree::expected_attribute< char > (
        "startdate",
        "");
    }

    if (!enddate_.present ())
    {
      throw ::xsd::cxx::tree::expected_attribute< char > (
        "enddate",
        "");
    }

    if (!dives_.present ())
    {
      throw ::xsd::cxx::tree::expected_attribute< char > (
        "dives",
        "");
    }
  }

  numberofdives* numberofdives::
  _clone (::xml_schema::flags f,
          ::xml_schema::container* c) const
  {
    return new class numberofdives (*this, f, c);
  }

  numberofdives& numberofdives::
  operator= (const numberofdives& x)
  {
    if (this != &x)
    {
      static_cast< ::xml_schema::type& > (*this) = x;
      this->startdate_ = x.startdate_;
      this->enddate_ = x.enddate_;
      this->dives_ = x.dives_;
    }

    return *this;
  }

  numberofdives::
  ~numberofdives ()
  {
  }
}

#include <ostream>

namespace streit
{
  ::std::ostream&
  operator<< (::std::ostream& o, const numberofdives& i)
  {
    o << ::std::endl << "startdate: " << i.startdate ();
    o << ::std::endl << "enddate: " << i.enddate ();
    o << ::std::endl << "dives: " << i.dives ();
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

